#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include "player/player.h"
#include "entity/entity.h"
#include "utilities/utilities.h"
#include <Windows.h>

vector2 screen_size = vector2(80, 20);

void input_cmd_yes_or_no(std::string question, bool *result)
{
    std::printf("%s For select, enter Y/n\n", question.c_str());
    std::string input;
    std::cin >> input;
    if (input == "Y" || input == "y")
        *result = true;
    else if (input == "n" || input == "N")
        *result = false;
    else
        *result = false;
}

/**
 * @brief Use this to render text by position on screen and sing axis x and y new value (position) by calculate end point a text
 *
 * @param text text to draw on screen
 * @param position_draw position to draw on screen
 * @param current_position_x current position axis x on screen
 * @param current_position_y current position axis y on screen
 * @param is_centered Centered position rendering text
 * @return true text has been rendered correctly
 * @return false text hasn't been rendered
 */
bool draw_string(std::string text, vector2 position_draw, int *current_position_x, int *current_position_y, bool is_centered)
{
    vector2 text_size = vector2(text.length(), 0);
    vector2 calculate_text_to_center = position_draw - (text_size / 2);
    vector2 current_position = vector2(*current_position_x, *current_position_y);
    if (is_centered && current_position != calculate_text_to_center)
        return false;

    if (!is_centered && current_position != position_draw)
        return false;

    *current_position_x += text_size.x;
    std::printf("%s", text.c_str());
    return true;
}

void draw_main_menu()
{
    bool is_active_menu = true;
    int menu_page = 0;
    while (is_active_menu)
    {
        utilities::cmd::clear();
        for (int y = 0; y < screen_size.y; y++)
        {
            for (int x = 0; x < screen_size.x; x++)
            {
                if (utilities::is_key_present(38))
                    menu_page++;
                if (utilities::is_key_present(40))
                    menu_page--;

                if (utilities::is_key_present(13))
                {
                    switch (menu_page)
                    {
                    case 0:
                        is_active_menu = false;
                        break;
                    case 1:
                        exit(0);
                        break;
                    }
                }

                if (menu_page > 1)
                    menu_page = 0;
                else if (menu_page < 0)
                    menu_page = 1;

                draw_string(menu_page == 0 ? "> start game" : "start game", (screen_size / 2) - vector2(0, 1), &x, &y, true);
                draw_string(menu_page == 1 ? "> close" : "close", (screen_size / 2) + vector2(0, 1), &x, &y, true);
                if ((y == screen_size.y - 1 || y == 0) || (x == screen_size.x - 1 || x == 0))
                    std::printf("#");
                else
                    std::printf(" ");
            }
            std::printf("\n");
        }
    }
}

void draw_main_level()
{
    int game_tick = 0;
    int spawn_object_tick = 100;
    std::vector<entity> entity_list;
    bool is_dead = false;
    player local_player = player();

    while (!is_dead)
    {
        game_tick++;

        if (game_tick >= spawn_object_tick)
        {
            spawn_object_tick = game_tick + 100;
            vector2 new_entity_position = vector2(utilities::generate_random_number(1, screen_size.x - 1), utilities::generate_random_number(6, screen_size.y - 1));
            entity_list.push_back(entity(new_entity_position, utilities::generate_random_number<int>(0, 1) ? true : false, game_tick));
        }

        if (utilities::is_key_present(87) || utilities::is_key_present(119))
            local_player.set_direction_movement(player::direction_move::forward);
        if (utilities::is_key_present(68) || utilities::is_key_present(100))
            local_player.set_direction_movement(player::direction_move::to_the_right);
        if (utilities::is_key_present(83) || utilities::is_key_present(115))
            local_player.set_direction_movement(player::direction_move::back);
        if (utilities::is_key_present(65) || utilities::is_key_present(97))
            local_player.set_direction_movement(player::direction_move::to_the_left);

        local_player.rais_stamina();

        utilities::cmd::clear();
        for (int y = 0; y < screen_size.y; y++)
        {
            for (int x = 0; x < screen_size.x; x++)
            {
                std::string number_points = "number of points : 10";
                std::string currents_health = "currents health : " + std::to_string(local_player.health) + "%";
                std::string current_stamina = "current stamina : " + std::to_string(static_cast<int>(local_player.stamina)) + "%";
                draw_string(number_points, vector2(5, 2), &x, &y, false);
                draw_string(currents_health, vector2(screen_size.x - (5 + currents_health.length()), 2), &x, &y, false);
                draw_string(current_stamina, vector2(screen_size.x - (7 + currents_health.length() + current_stamina.length()), 2), &x, &y, false);
                if ((y == screen_size.y - 1 || y == 0 || y == 4) || (x == screen_size.x - 1 || x == 0))
                    std::printf("#");
                else
                    std::printf(" ");
            }
            std::printf("\n");
        }
        local_player.draw_player();

        for (int i = 0; i < entity_list.size(); i++)
        {
            entity eat = entity_list[i];
            if (eat.is_destroy)
                continue;

            if (eat.time_creat + eat.time_to_rotten <= game_tick)
                eat.is_dangerous = true;

            if (eat.entity_position == local_player.player_position)
            {
                if (eat.is_dangerous)
                    local_player.get_damage();
                else
                    local_player.eats_food();

                eat.is_destroy = true;
                continue;
            }

            eat.draw_entity();
        }
    }
}

int main(int, char **)
{
    // bool eddit_setting_screen = false;
    // while (!eddit_setting_screen)
    // {
    //     std::printf("Please input your cmd size...\n");
    //     std::cin >> screen_size.x >> screen_size.y;
    //     if (screen_size.x < 80)
    //     {
    //         std::printf("Sorry, minimum screen width is 80. Please enter again.\n");
    //         utilities::cmd::pause();
    //         utilities::cmd::clear();
    //         continue;
    //     }
    //     input_cmd_yes_or_no("Is his screen size " + std::to_string(screen_size.x) + "x" + std::to_string(screen_size.y) + " exactly right ?", &eddit_setting_screen);
    //     if (eddit_setting_screen && (screen_size.x % 2 != 0))
    //         screen_size.y += 1;
    // }
    // utilities::cmd::clear();
    // draw_main_menu();
    draw_main_level();
}

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include "player/player.h"
#include "entity/entity.h"
#include "utilities/utilities.h"
#include "game_configuration.h"
#include <Windows.h>

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

                utilities::cmd::draw_string(menu_page == 0 ? "> start game" : "start game", (screen_size / 2) - vector2(0, 1), &x, &y, true);
                utilities::cmd::draw_string(menu_page == 1 ? "> close" : "close", (screen_size / 2) + vector2(0, 1), &x, &y, true);
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
    player local_player = player();

    while (local_player.is_dead())
    {
        game_tick++;
        local_player.move_handler();

        local_player.rais_stamina();
        entity::spawn_new_entity();

        utilities::cmd::clear();
        for (int y = 0; y < screen_size.y; y++)
        {
            for (int x = 0; x < screen_size.x; x++)
            {
                std::string number_points = "number of points : " + std::to_string(local_player.player_point);
                std::string currents_health = "currents health : " + std::to_string(local_player.health) + "%";
                std::string current_stamina = "current stamina : " + std::to_string(static_cast<int>(local_player.stamina)) + "%";
                utilities::cmd::draw_string(number_points, vector2(5, 2), &x, &y, false);
                utilities::cmd::draw_string(currents_health, vector2(screen_size.x - (5 + currents_health.length()), 2), &x, &y, false);
                utilities::cmd::draw_string(current_stamina, vector2(screen_size.x - (7 + currents_health.length() + current_stamina.length()), 2), &x, &y, false);
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
            if (entity_list[i].is_food_ruined())
                entity_list[i].is_dangerous = true;

            if (entity_list[i].entity_position == local_player.player_position)
            {
                if (entity_list[i].is_dangerous)
                    local_player.get_damage();
                else
                    local_player.eats_food();

                entity::remove_entity(i);
                continue;
            }

            entity_list[i].draw_entity();
        }
    }
}

int main(int, char **)
{
    bool eddit_setting_screen = false;
    while (!eddit_setting_screen)
    {
        std::printf("Please input your cmd size...\n");
        std::cin >> screen_size.x >> screen_size.y;
        if (screen_size.x < 80)
        {
            std::printf("Sorry, minimum screen width is 80. Please enter again.\n");
            utilities::cmd::pause();
            utilities::cmd::clear();
            continue;
        }
        input_cmd_yes_or_no("Is his screen size " + std::to_string(screen_size.x) + "x" + std::to_string(screen_size.y) + " exactly right ?", &eddit_setting_screen);
        if (eddit_setting_screen && (screen_size.x % 2 != 0))
            screen_size.y += 1;
    }
    utilities::cmd::clear();
    draw_main_menu();
    draw_main_level();
}

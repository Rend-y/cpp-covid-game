#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "vector2/vector2.h"
#include <thread>
#include "utilities/utilities.h"

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
    while (is_active_menu)
    {
        utilities::cmd::clear();
        for (int y = 0; y < screen_size.y; y++)
        {
            for (int x = 0; x < screen_size.x; x++)
            {
                draw_string("start game", (screen_size / 2) - vector2(0, 1), &x, &y, true);
                draw_string("close", (screen_size / 2) + vector2(0, 1), &x, &y, true);
                if ((y == screen_size.y - 1 || y == 0) || (x == screen_size.x - 1 || x == 0))
                    std::printf("█");
                else
                    std::printf(" ");
            }
            std::printf("\n");
        }
    }
}

void draw_main_level()
{
    bool is_dead = false;
    while (!is_dead)
    {
        utilities::cmd::clear();
        for (int y = 0; y < screen_size.y; y++)
        {
            for (int x = 0; x < screen_size.x; x++)
            {
                std::string number_points = "number of points : 10";
                std::string currents_health = "currents health : 100%";
                std::string current_stamina = "current stamina : 100%";
                draw_string(number_points, vector2(5, 2), &x, &y, false);
                draw_string(currents_health, vector2(screen_size.x - (5 + currents_health.length()), 2), &x, &y, false);
                draw_string(current_stamina, vector2(screen_size.x - (7 + currents_health.length() + current_stamina.length()), 2), &x, &y, false);
                if ((y == screen_size.y - 1 || y == 0 || y == 4) || (x == screen_size.x - 1 || x == 0))
                    std::printf("█");
                else
                    std::printf(" ");
            }
            std::printf("\n");
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

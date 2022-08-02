#include <string>
#include <iostream>
#include <sstream>
#include "vector2/vector2.h"

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

void console_pause()
{
#ifdef _WIN32
    system("pause");
#else
    system("read");
#endif
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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

int main(int, char **)
{
    bool eddit_setting_screen = false;
    vector2 screen_size = vector2(0, 0);
    while (!eddit_setting_screen)
    {
        std::printf("Please input your cmd size...\n");
        std::cin >> screen_size.x >> screen_size.y;
        input_cmd_yes_or_no("Is his screen size " + std::to_string(screen_size.x) + "x" + std::to_string(screen_size.y) + " exactly right ?", &eddit_setting_screen);
        if (eddit_setting_screen && (screen_size.x % 2 != 0))
            screen_size.y += 1;
    }
    clear_screen();
    for (int y = 0; y < screen_size.y; y++)
    {
        for (int x = 0; x < screen_size.x; x++)
        {
            bool is_draw_start_game = draw_string("start game", (screen_size / 2) - vector2(0, 1), &x, &y, true);
            bool is_draw_exit = draw_string("close", (screen_size / 2) + vector2(0, 1), &x, &y, true);
            if (!is_draw_exit || !is_draw_start_game)
            {
                if ((y == screen_size.y - 1 || y == 0) || (x == screen_size.x - 1 || x == 0))
                    std::printf("█");
                else
                    std::printf(" ");
            }
        }
        std::printf("\n");
    }
}

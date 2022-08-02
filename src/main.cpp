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

void clear_screen()
{
#ifdef _WIN32
    system("pause");
    system("cls");
#else
    system("read");
    system("clear");
#endif
}

void draw_string(std::string text, vector2 position_draw, vector2 current_position, bool is_centered)
{
    vector2 text_size = vector2(text.length(), 0);
    if (is_centered)
    {
    }
}

int main(int, char **)
{
    bool eddit_setting_screen = false;
    vector2 screen_size = vector2(40, 20);
    // while (!eddit_setting_screen)
    // {
    //     std::printf("Please input your cmd or screen size...\n");
    //     std::cin >> screen_size.x >> screen_size.y;
    //     input_cmd_yes_or_no("Is his screen size " + std::to_string(screen_size.x) + "x" + std::to_string(screen_size.y) + " exactly right ?", &eddit_setting_screen);
    //     if (eddit_setting_screen)
    //         break;
    //     clear_screen();
    // }
    for (int y = 0; y < screen_size.y; y++)
    {
        for (int x = 0; x < screen_size.x; x++)
        {
            if (y == screen_size.y - 1 || y == 0)
                std::printf("A");
            else if (x == screen_size.x - 1 || x == 0)
                std::printf("A");
            else
                std::printf(" ");
        }
        std::printf("\n");
    }
}

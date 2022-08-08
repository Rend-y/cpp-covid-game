#include "utilities.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

void utilities::cmd::clear()
{
    utilities::cmd::set_cursor_position(0, 0);
}

bool utilities::is_key_present(int key_code)
{
    return GetAsyncKeyState(key_code) & 0x8000;
}

void utilities::sleep_for_milliseconds(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void utilities::cmd::set_cursor_position(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool utilities::cmd::draw_string(std::string text, vector2 position_draw, int *current_position_x, int *current_position_y, bool is_centered)
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

void utilities::cmd::pause()
{
    system("pause");
}
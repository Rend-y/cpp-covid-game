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

void utilities::cmd::pause()
{
    system("pause");
}
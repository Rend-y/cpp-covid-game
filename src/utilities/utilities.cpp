#include "utilities.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

void utilities::cmd::clear()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool utilities::is_key_present(int key_code)
{
    return GetAsyncKeyState(key_code) & 0x8000;
}

void utilities::sleep_for_milliseconds(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void utilities::cmd::pause()
{
    system("pause");
}
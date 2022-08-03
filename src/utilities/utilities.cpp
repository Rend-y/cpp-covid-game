#include "utilities.h"
#include <iostream>

void utilities::cmd::clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void utilities::cmd::pause()
{
#ifdef _WIN32
    system("pause");
#else
    system("read");
#endif
}
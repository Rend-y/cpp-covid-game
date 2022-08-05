#include "vector2.h"

bool vector2::is_empty()
{
    return this->x == 0 && this->y == 0;
}

void vector2::operator+=(vector2 new_value)
{
    this->x += new_value.x;
    this->y += new_value.y;
}

void vector2::operator-=(vector2 new_value)
{
    this->x -= new_value.x;
    this->y -= new_value.y;
}

void vector2::operator=(vector2 new_value)
{
    this->x = new_value.x;
    this->y = new_value.y;
}

vector2 vector2::operator+(vector2 value)
{
    return vector2(this->x + value.x, this->y + value.y);
}

vector2 vector2::operator-(vector2 value)
{
    return vector2(this->x - value.x, this->y - value.y);
}

vector2 vector2::operator*(vector2 value)
{
    return vector2(this->x * value.x, this->y * value.y);
}

vector2 vector2::operator/(vector2 value)
{
    return vector2(this->x / value.x, this->y / value.y);
}

vector2 vector2::operator*(int value)
{
    return vector2(this->x / value, this->y / value);
}

vector2 vector2::operator/(int value)
{
    return vector2(this->x / value, this->y / value);
}

bool vector2::operator==(vector2 equal)
{
    return (this->x == equal.x && this->y == equal.y);
}

bool vector2::operator!=(vector2 equal)
{
    return (this->x != equal.x || this->y != equal.y);
}
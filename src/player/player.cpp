#include "player.h"
#include <iostream>
#include "../utilities/utilities.h"

void player::get_damage()
{
    this->health -= this->damage_points;
}

void player::rais_stamina()
{
    if (this->stamina - this->speed_devastation_stamina <= 0)
    {
        this->get_damage();
        this->stamina = 100;
    }
    this->stamina -= this->speed_devastation_stamina;
}

void player::set_direction_movement(player::direction_move to_move)
{
    switch (to_move)
    {
    case player::direction_move::forward:
        if (this->player_position.y > 5)
            this->player_position -= vector2(0, 1);
        break;
    case player::direction_move::to_the_right:
        this->player_position += vector2(1, 0);
        break;
    case player::direction_move::back:

        this->player_position += vector2(0, 1);
        break;
    case player::direction_move::to_the_left:
        if (this->player_position.x > 1)
            this->player_position -= vector2(1, 0);
        break;
    }
}

void player::draw_player()
{
    utilities::cmd::set_cursor_position(this->player_position.x, this->player_position.y);
    std::printf("%s", this->player_on_the_screen.c_str());
}

void player::eats_food()
{
    this->stamina += this->adding_stamina_when_eating;
}
#include "player.h"

void player::get_damage()
{
    this->health -= this->damage_points;
}

void player::rais_stamina()
{
    this->stamina -= this->speed_devastation_stamina;
}

void player::set_direction_movement(player::direction_move to_move)
{
    switch (to_move)
    {
    case player::direction_move::forward:
        this->player_position -= vector2(0, 1);
        break;
    case player::direction_move::to_the_right:
        this->player_position += vector2(1, 0);
        break;
    case player::direction_move::back:
        this->player_position += vector2(1, 0);
        break;
    case player::direction_move::to_the_left:
        this->player_position -= vector2(0, 1);
        break;
    }
}

void player::eats_food()
{
    this->stamina += this->adding_stamina_when_eating;
}
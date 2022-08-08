#include "player.h"
#include <iostream>
#include "../utilities/utilities.h"
#include "../game_configuration.h"

void player::get_damage()
{
    this->player_point -= 5;
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
    int result_player_speed = 1;
    if (this->stamina >= 75)
        result_player_speed = player::player_speed::when_not_hungry;
    else if (this->stamina >= 50)
        result_player_speed = player::player_speed::default;
    else
        result_player_speed = player::player_speed::when_hungry;

    switch (to_move)
    {
    case player::direction_move::forward:
        if (this->player_position.y > 5)
            this->player_position -= vector2(0, result_player_speed);
        break;
    case player::direction_move::to_the_right:
        if (this->player_position.x + result_player_speed < screen_size.x)
            this->player_position += vector2(result_player_speed, 0);
        break;
    case player::direction_move::back:
        if (this->player_position.y + result_player_speed < screen_size.y)
            this->player_position += vector2(0, result_player_speed);
        break;
    case player::direction_move::to_the_left:
        if (this->player_position.x > 1)
            this->player_position -= vector2(result_player_speed, 0);
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
    this->player_point += 1;
    this->stamina += this->adding_stamina_when_eating;
}
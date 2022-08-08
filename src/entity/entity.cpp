#include "entity.h"
#include <iostream>
#include <string>

#include "../utilities/utilities.h"
#include "../game_configuration.h"

void entity::draw_entity()
{
    utilities::cmd::set_cursor_position(this->entity_position.x, this->entity_position.y);
    std::printf("%s", this->is_dangerous ? "*" : "@");
}

vector2 entity::generate_random_spawn_position()
{
    return vector2(utilities::generate_random_number(1, screen_size.x - 1), utilities::generate_random_number(6, screen_size.y - 1));
}

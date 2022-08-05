#include "entity.h"
#include <iostream>
#include <string>

#include "../utilities/utilities.h"

void entity::draw_entity()
{
    utilities::cmd::set_cursor_position(this->entity_position.x, this->entity_position.y);
    std::printf("%s", this->is_dangerous ? "*" : "@");
}
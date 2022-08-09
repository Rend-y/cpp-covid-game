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

bool entity::is_food_ruined()
{
    return this->time_creat + this->time_to_rotten <= game_tick;
}

void entity::remove_entity(int index)
{
    entity_list.erase(entity_list.begin() + index);
}

void entity::spawn_new_entity()
{
    if (game_tick >= spawn_object_tick)
    {
        int get_random_time_to_spawn = utilities::generate_random_number(15, 100);
        spawn_object_tick = game_tick + get_random_time_to_spawn;
        entity_list.push_back(entity(static_cast<float>(utilities::generate_random_number<int>(1, 100) / 100) > 0.75f ? true : false, game_tick));
    }
}

vector2 entity::generate_random_spawn_position()
{
    return vector2(utilities::generate_random_number(1, screen_size.x - 1), utilities::generate_random_number(6, screen_size.y - 1));
}

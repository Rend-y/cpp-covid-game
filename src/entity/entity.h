#pragma once
#include "../vector2/vector2.h"
#include "../utilities/utilities.h"

class entity
{
private:
public:
    int time_to_rotten = 450;

    int time_creat = 0;

    vector2 entity_position = vector2(0, 0);
    bool is_dangerous = false;

    entity(bool is_dangerous, int time_creat) : time_to_rotten(utilities::generate_random_number(100, 300)), entity_position(generate_random_spawn_position()), is_dangerous(is_dangerous), time_creat(time_creat) {}

    /**
     * @brief use this to draw the eat in the console
     *
     */
    void draw_entity();

    vector2 generate_random_spawn_position();
};
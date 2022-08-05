#pragma once
#include "../vector2/vector2.h"

class entity
{
private:
public:
    int time_to_rotten = 450;

    int time_creat = 0;

    bool is_destroy = false;
    vector2 entity_position = vector2(0, 0);
    bool is_dangerous = false;

    entity(vector2 entity_position, bool is_dangerous, int time_creat) : entity_position(entity_position), is_dangerous(is_dangerous), time_creat(time_creat) {}

    /**
     * @brief use this to draw the eat in the console
     *
     */
    void draw_entity();
};
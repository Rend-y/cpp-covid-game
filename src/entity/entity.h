#include "../vector2/vector2.h"

class entity
{
private:
public:
    vector2 entity_position = vector2(0, 0);
    bool is_dangerous = false;

    entity(vector2 entity_position, bool is_dangerous) : entity_position(entity_position), is_dangerous(is_dangerous) {}
};
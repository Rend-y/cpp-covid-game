#include "../vector2/vector2.h"

class player
{
private:
    int health = 100;
    int stamina = 100;

    int damage_points = 25;
    int speed_devastation_stamina = 5;
    int adding_stamina_when_eating = 10;

    vector2 player_position = vector2(0, 0);

public:
    /**
     * @brief This is a sides to move
     *
     */
    enum direction_move
    {
        forward = 0,
        to_the_right,
        back,
        to_the_left,
    };

    /**
     * @brief use it to create a new class player
     *
     */
    player()
    {
    }

    /**
     * @brief use this to move the player on the side
     *
     * @param to_move the side to move player on screen
     */
    void set_direction_movement(direction_move to_move);

    /**
     * @brief use this to the hit player
     *
     */
    void get_damage();

    /**
     * @brief use this to the remove player eat (stamina)
     *
     */
    void rais_stamina();

    /**
     * @brief use this to the added player eat (stamina)
     *
     */
    void eats_food();
};
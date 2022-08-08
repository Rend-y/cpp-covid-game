#pragma once
#include <random>
#include "../vector2/vector2.h"

namespace utilities
{
    /**
     * @brief use this to processing key down events
     *
     * @param key_code button code to ASCII
     * @return true button has been pressed
     * @return false button hasn't been pressed
     */
    bool is_key_present(int key_code);

    /**
     * @brief use this to the generate randon nubmer from min and max values
     *
     * @tparam T
     * @param min this is a minimum value that will be used to generate
     * @param max this is a maximum value that will be used to generate
     * @return T this is a random number after the generate
     */
    template <typename T = int>
    T generate_random_number(T min, T max)
    {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<> distr(static_cast<float>(min), static_cast<float>(max));
        return static_cast<T>(distr(eng));
    }

    /**
     * @brief use it's to sleep current thread on N time  milliseconds
     *
     * @param milliseconds times sleep to thread
     */
    void sleep_for_milliseconds(int milliseconds);

    namespace cmd
    {

        /**
         * @brief Use this to render text by position on screen and sing axis x and y new value (position) by calculate end point a text
         *
         * @param text text to draw on screen
         * @param position_draw position to draw on screen
         * @param current_position_x current position axis x on screen
         * @param current_position_y current position axis y on screen
         * @param is_centered Centered position rendering text
         * @return true text has been rendered correctly
         * @return false text hasn't been rendered
         */
        bool draw_string(std::string text, vector2 position_draw, int *current_position_x, int *current_position_y, bool is_centered);

        /**
         * @brief use this to clear console from all commands
         *
         */
        void clear();

        /**
         * @brief use this to set point draw on the console
         *
         * @param x point to draw on asix x
         * @param y point to draw on asix y
         */
        void set_cursor_position(int x, int y);

        /**
         * @brief Use this for putting console on pause and waiting to enter any commands
         *
         */
        void pause();
    }
}
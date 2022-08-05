#pragma once
#include <random>

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
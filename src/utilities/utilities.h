namespace utilities
{
    bool is_key_present(int key_code);

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
         * @brief Use this for putting console on pause and waiting to enter any commands
         *
         */
        void pause();
    }
}
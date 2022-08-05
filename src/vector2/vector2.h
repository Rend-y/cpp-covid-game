#pragma once
class vector2
{
public:
    int x, y;
    vector2(int x = 0, int y = 0) : x(x), y(y) {}

    /**
     * @brief use this to the check vector on the zero value
     *
     * @return true this vector is have the zero value
     * @return false this vector isn't have the zero value
     */
    bool is_empty();

    /**
     * @brief use this to the added value from the new vector (aka new_value) to current vector
     *
     * @param new_value this is a new value to added in the vector
     */
    void operator+=(vector2 new_value);

    /**
     * @brief use this to the substractions value from the new vector (aka new_value) to current vector
     *
     * @param new_value this is a new value to substractions in the vector
     */
    void operator-=(vector2 new_value);

    /**
     * @brief use this to the equate new vector to current vector
     *
     * @param new_value this is a new value to equate to the current vector
     */
    void operator=(vector2 new_value);

    vector2 operator+(vector2 value);

    vector2 operator-(vector2 value);

    vector2 operator*(vector2 value);

    vector2 operator/(vector2 value);

    vector2 operator*(int value);

    vector2 operator/(int value);

    /**
     * @brief use this to the equals current vector with to the equal value
     *
     * @param equal this is value to be compared
     * @return true both vector is equal
     * @return false one vector isn't equal
     */
    bool operator==(vector2 equal);

    /**
     * @brief use this to the equals current vector with to the equal value
     *
     * @param equal this is value to be compared
     * @return true false one vector isn't equal
     * @return false true both vector is equal
     */
    bool operator!=(vector2 equal);
};

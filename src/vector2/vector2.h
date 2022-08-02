class vector2
{
public:
    int x, y;
    vector2(int x = 0, int y = 0) : x(x), y(y) {}

    bool is_empty();

    void operator+=(vector2 new_value);

    void operator-=(vector2 new_value);

    vector2 operator=(vector2 new_value);

    vector2 operator+(vector2 value);

    vector2 operator-(vector2 value);

    bool operator==(vector2 equal);

    bool operator!=(vector2 equal);
};

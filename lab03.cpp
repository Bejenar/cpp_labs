#include <array>

struct Leg
{
    int length;
};

struct Arm
{
    int power;
};

struct Person
{
    std::array<Leg, 2> legs;
    Arm arms[2];
};

int main()
{
    Person person;
}

// Leg, int, Arm, Person, std::array<Leg, 2>
// length, power, legs[0], legs[1], arms[0], arms[1], person
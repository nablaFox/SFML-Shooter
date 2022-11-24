#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class Collision
{
public:
    Collision(CircleShape *circle1, CircleShape *circle2);
    void circlesColl();

private:

    CircleShape *circle1;
    CircleShape *circle2;

};

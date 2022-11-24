#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacle: public CircleShape {
public:
    Obstacle(float radius, int posX, int posY) : CircleShape(radius) {
        setOrigin(getRadius(), getRadius());
        setPosition(posX, posY);
        setFillColor(Color(55, 55, 55));
    }

private:
};
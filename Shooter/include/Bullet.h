#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet : public CircleShape {
public:
    Bullet(float radius, float dirX, float dirY) : CircleShape(radius) {
        directionX = dirX;
        directionY = dirY;
        setFillColor(Color(230, 230, 230));
    }

    void shoot(float v) {
        move(v * directionX, v * directionY);
    }

    bool isOut(RenderWindow &w) {
        if (getPosition().x > w.getSize().x || getPosition().x < 0)
            return true;
        if (getPosition().y > w.getSize().y || getPosition().y < 0)
            return true; 
    }

private:
    float directionX, directionY;
};
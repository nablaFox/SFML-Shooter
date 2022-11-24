#include "Collision.h"

const float pi = 3.14159265358979323846;

Collision::Collision(CircleShape *circle1, CircleShape *circle2)
{
    this->circle1 = circle1;
    this->circle2 = circle2;
}

void Collision::circlesColl()
{
    float dx = circle2->getPosition().x - circle1->getPosition().x;
    float dy = circle2->getPosition().y - circle1->getPosition().y;
    float d = sqrt((dx * dx) + (dy * dy));

    if (d < circle1->getRadius() + circle2->getRadius()) {
        float deg = atan2(dy, dx);
        float distanceToMove = circle1->getRadius() + circle2->getRadius() - d;
        Vector2f offset = Vector2f(cos(deg) * distanceToMove, sin(deg) * distanceToMove);
        circle2->move(offset.x, offset.y);
    }
}

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <iostream>

#include "Bullet.h"
#include "Obstacle.h"

using namespace std;
using namespace sf;

class Shooter {
public:
    Shooter(int posX, int posY, RenderWindow *window, float vp = 3, float vb = 5);
    ~Shooter();
    void aim(int x, int y);
    void play() {
        fire();
        move();
        draw();
    }

private:
    RenderWindow *playSpace;
    CircleShape *player;
    RectangleShape *gun;

    vector<Bullet> bullets;
    vector<Obstacle> obstacles;

    void fire();
    void animBullets();
    void move();
    void draw();

    int rectX, rectY;
    float dirX, dirY, vp, vb;
};
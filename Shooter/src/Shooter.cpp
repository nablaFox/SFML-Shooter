#include "Shooter.h"
#include "Collision.h"

#define _USE_MATH_DEFINES

Shooter::Shooter(int posX, int posY, RenderWindow *window, float vp, float vb)
{
    playSpace = window;
    this->vb = vb;
    this->vp = vp;
    
    player = new CircleShape(40);
    player->setFillColor(Color(127, 53, 184));
    player->setOrigin(player->getRadius(), player->getRadius());
    player->setPosition(posX, posY);

    gun = new RectangleShape(Vector2f(60, 20));
    gun->setFillColor(Color::White);
    gun->setOrigin(0, gun->getSize().y / 2);
    gun->setPosition(player->getPosition().x, player->getPosition().y);

    obstacles.push_back(Obstacle(60, playSpace->getSize().x * 0.12, playSpace->getSize().y * 0.12));
    obstacles.push_back(Obstacle(30, playSpace->getSize().x * 0.06, playSpace->getSize().y * 0.25));
    obstacles.push_back(Obstacle(80, playSpace->getSize().x * 0.85, playSpace->getSize().y * 0.73));
    obstacles.push_back(Obstacle(50, playSpace->getSize().x * 0.3, playSpace->getSize().y * 0.65));
}

void Shooter::aim(int x, int y)
{
    //get direction
    float dy = y - player->getPosition().y;
    float dx = x - player->getPosition().x;
    dirX = cos(atan2(dy, dx));
    dirY = sin(atan2(dy, dx));

    //get gun coords
    rectX = gun->getSize().x * dirX + player->getPosition().x;
    rectY = gun->getSize().x * dirY + player->getPosition().y;

    //rotate for aim
    double deg = atan2(dy, dx) * 180 / M_PI;
    gun->setRotation(deg);
}

void Shooter::fire()
{
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        bullets.push_back(Bullet(10, dirX, dirY));
        bullets.back().setOrigin(bullets.back().getRadius(), bullets.back().getRadius());
        bullets.back().setPosition(rectX, rectY);
    }

    animBullets();
}

void Shooter::animBullets()
{
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].shoot(vb);
        if (bullets[i].isOut(*playSpace))
            bullets.erase(bullets.begin() + i);
        for (int j = 0; j < obstacles.size(); j ++)
            Collision(&obstacles[j], &bullets[i]).circlesColl();
    }
}

void Shooter::move()
{
    float pX = player->getPosition().x;
    float pY = player->getPosition().y;
    float r = player->getRadius();
    
    aim(Mouse::getPosition(*playSpace).x, Mouse::getPosition(*playSpace).y);
    gun->setPosition(pX, pY);

    if (pX > r || Keyboard::isKeyPressed(Keyboard::D))
        if (Keyboard::isKeyPressed(Keyboard::A))
            player->move(vp * -1, 0);
    if (pX < playSpace->getSize().x - r|| Keyboard::isKeyPressed(Keyboard::A))
        if (Keyboard::isKeyPressed(Keyboard::D))
            player->move(vp * 1, 0);
    if (pY > r || Keyboard::isKeyPressed(Keyboard::S))
        if (Keyboard::isKeyPressed(Keyboard::W))
            player->move(0, vp * -1);
    if (pY < playSpace->getSize().y - r || Keyboard::isKeyPressed(Keyboard::W))
        if (Keyboard::isKeyPressed(Keyboard::S))
            player->move(0, vp * 1);

    for (int j = 0; j < obstacles.size(); j ++)
        Collision(&obstacles[j], player).circlesColl();
}

void Shooter::draw()
{
    for (const Bullet &bullet : bullets)
        playSpace->draw(bullet);
    for (const Obstacle &obstacle : obstacles)
        playSpace->draw(obstacle);
    playSpace->draw(*player);
    playSpace->draw(*gun);
}

Shooter::~Shooter()
{
    delete player;
    delete playSpace;
    delete gun;
}
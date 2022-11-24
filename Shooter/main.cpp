#include <SFML/Graphics.hpp>

#include "Shooter.h"

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(1368, 798), "SFML Shooter!", Style::Default, settings);
    window.setFramerateLimit(240);

    Shooter shooter(window.getSize().x / 2, window.getSize().y / 2, &window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseMoved)
                shooter.aim(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
        }

        window.clear();
        shooter.play();
        window.display();
    }

    return 0;
}
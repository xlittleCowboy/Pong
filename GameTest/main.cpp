#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Ball.h"
#include "Score.h"
#include "Audio.h"

/*
    MOVE PLAYER WITH MOUSE
    PRESS R TO RESTART
    CHANGE BALL, PLAYER & SCORE PARAMETERS AT THE START OF main()
*/

int main()
{
    // Window Setup
    const int WindowWidth = 800;
    const int WindowHeight = 800;

    RenderWindow Window(VideoMode(WindowWidth, WindowHeight), "Pong", sf::Style::Close);
    Window.setVerticalSyncEnabled(true);

    // Ball, Player & Score Setup
    Ball* MainBall = new Ball(10.0f, 15.0f, WindowWidth, WindowHeight, sf::Color(233, 0, 100));

    Player* MainPlayer = new Player(sf::Vector2f(10.0f, 100.0f), sf::Color(179, 0, 94));

    Score* MainScore = new Score(sf::Vector2f(WindowWidth / 2, 10), sf::Color(179, 0, 94));

    // Main Loop
    while (Window.isOpen())
    {
        Event Event;
        while (Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                Window.close();
            }
            if (Event.type == sf::Event::KeyPressed)
            {
                if (Event.key.code == sf::Keyboard::Escape)
                {
                    Window.close();
                }

                if (Event.key.code == sf::Keyboard::R)
                {
                    delete MainBall;
                    delete MainPlayer;
                    delete MainScore;

                    MainBall = new Ball(10.0f, 15.0f, WindowWidth, WindowHeight, sf::Color(233, 0, 100));

                    MainPlayer = new Player(sf::Vector2f(10.0f, 100.0f), sf::Color(179, 0, 94));

                    MainScore = new Score(sf::Vector2f(WindowWidth / 2, 10), sf::Color(179, 0, 94));
                }
            }
        }

        // Draw & Display
        Window.clear();

        sf::RectangleShape Background;
        Background.setSize(sf::Vector2f(WindowWidth, WindowHeight));
        Background.setFillColor(sf::Color(6, 0, 71));
        Window.draw(Background);
        
        MainBall->Update(MainPlayer->GetPosition(), MainPlayer->GetSize().y, Window, MainScore);
        MainPlayer->Update(Mouse::getPosition(Window).y, WindowHeight, Window);

        Window.display();
    }

    delete MainBall;
    delete MainPlayer;

    return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <random>

#include "Player.h"
#include "Ball.h"

using namespace sf;
using namespace std;

int main()
{
    int window_width = 1280, window_height = 720;

    RenderWindow window(VideoMode(window_width, window_height), "Ping-Pong!");
    window.setVerticalSyncEnabled(true);

    Ball ball(10.f, 15.f);

    Player player(10.f, 100.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
            }
        }

        ball.moveBall();
        ball.checkBorderCollision(window_width, window_height);
        ball.checkPlayerCollision(player.player_shape.getPosition().x, player.player_shape.getPosition().y, player.player_height);

        player.movePlayer(Mouse::getPosition(window).y, window_height);

        window.clear();
        window.draw(ball.shape);
        window.draw(player.player_shape);
        window.display();
    }

    return 0;
}
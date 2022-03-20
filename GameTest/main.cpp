#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Ball.h"
#include "Score.h"
#include "Audio.h"

using namespace sf;

int main()
{
    int window_width = 1280, window_height = 720;

    RenderWindow window(VideoMode(window_width, window_height), "Ping-Pong!");
    window.setVerticalSyncEnabled(true);

    Ball ball(15.f, 15.f);

    Player player(10.f, 100.f);

    Score score(window_width);

    Audio audio;

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
        if (ball.checkBorderCollision(window_width, window_height))
            audio.playSound();
        if (ball.checkPlayerCollision(player.player_shape.getPosition().x, player.player_shape.getPosition().y, player.player_height))
        {
            score.updateScore();
            audio.playSound();
        }

        player.movePlayer(Mouse::getPosition(window).y, window_height);

        window.clear();
        window.draw(ball.shape);
        window.draw(player.player_shape);
        window.draw(score.text);
        window.display();
    }

    return 0;
}
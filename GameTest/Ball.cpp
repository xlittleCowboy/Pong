#include "Ball.h"

Ball::Ball(float speed, float radius)
{
    this->speed = speed;
    this->radius = radius;
    this->playerTrigger = true;

    shape.setRadius(radius);
    shape.setFillColor(Color::Red);
    shape.setPosition(640, 360);

    getStartDirection();
}

void Ball::getStartDirection()
{
    Random generator;
    float random_value = generator.getRandomNumber(-360.f, 360.f);

    float x = shape.getPosition().x + cos(random_value);
    float y = shape.getPosition().y + sin(random_value);
    direction = Vector2f(x - shape.getPosition().x, y - shape.getPosition().y);
}

void Ball::moveBall()
{
    shape.move(direction * speed);
}

bool Ball::checkBorderCollision(const int window_width, const int window_height)
{
    if (shape.getPosition().y <= -radius / 2
        || shape.getPosition().y >= window_height - radius * 2)
    {
        direction.y *= -1;
        playerTrigger = true;
        return true;
    }

    if (shape.getPosition().x >= window_width - radius * 2)
    {
        direction.x *= -1;
        playerTrigger = true;
        return true;
    }

    return false;
}

bool Ball::checkPlayerCollision(const float player_x, const float player_y, const float player_height)
{
    if (playerTrigger)
    {
        if (shape.getPosition().y >= player_y - radius
            && shape.getPosition().y <= player_y + player_height
            && shape.getPosition().x <= player_x + radius
            && shape.getPosition().x >= player_x)
        {
            direction.x *= -1;
            playerTrigger = false;
            return true;
        }
    }

    if (shape.getPosition().x <= -radius * 2)
    {
        direction.x = 0;
        direction.y = 0;
    }

    return false;
}
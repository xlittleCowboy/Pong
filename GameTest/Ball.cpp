#include "Ball.h"

Ball::Ball(float speed, float radius)
{
    this->speed = speed;
    this->radius = radius;

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

void Ball::checkBorderCollision(const int window_width, const int window_height)
{
    if (shape.getPosition().y <= -radius / 2)
        direction.y *= -1;
    else if (shape.getPosition().y >= window_height - radius * 2)
        direction.y *= -1;

    if (shape.getPosition().x >= window_width - radius * 2)
        direction.x *= -1;
}

void Ball::checkPlayerCollision(const float player_x, const float player_y, const float player_height)
{
    if (shape.getPosition().y >= player_y
        && shape.getPosition().y <= player_y + player_height
        && shape.getPosition().x <= player_x + radius)
        direction.x *= -1;
}
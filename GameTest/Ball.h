#pragma once

#include <SFML/Graphics.hpp>
#include "rnd.h"

using namespace sf;

class Ball
{
public:
    float speed;
    float radius;
    CircleShape shape;
    Vector2f direction;

    Ball(float speed, float radius);

    void getStartDirection();

    void moveBall();

    void checkBorderCollision(const int window_width, const int window_height);

    void checkPlayerCollision(const float player_x, const float player_y, const float player_height);
};


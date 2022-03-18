#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
    float player_width, player_height;
    RectangleShape player_shape;

    Player(float player_width, float player_height);

    void movePlayer(const int mouse_position_y, const int window_height);
};


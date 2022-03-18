#include "Player.h"

Player::Player(float player_width, float player_height)
{
    this->player_width = player_width;
    this->player_height = player_height;

    player_shape.setSize(Vector2f(player_width, player_height));
    player_shape.setFillColor(Color::White);
}

void Player::movePlayer(const int mouse_position_y, const int window_height)
{
    float player_x = player_width / 2;
    float player_y = .0f;
    if (mouse_position_y - player_height / 2 < 0)
        player_y = 0.f;
    else if (mouse_position_y + player_height / 2 > window_height)
        player_y = window_height - player_height;
    else
        player_y = mouse_position_y - player_height / 2;
    player_shape.setPosition(Vector2f(player_x, player_y));
}
#include "Player.h"

Player::Player(sf::Vector2f Size, const sf::Color& Color)
{
    Shape.setSize(Size);
    Shape.setFillColor(Color);
    Shape.setOutlineColor(sf::Color::White);
    Shape.setOutlineThickness(2.5f);
}

void Player::Update(int MouseY, int BorderHeight, sf::RenderWindow& Window)
{
    float Width = Shape.getSize().x;
    float Height = Shape.getSize().y;

    float X = Width / 2;
    float Y = 0.0f;

    if (MouseY - Height / 2 < 0)
        Y = 0.0f;
    else if (MouseY + Height / 2 > BorderHeight)
        Y = BorderHeight - Height;
    else
        Y = MouseY - Height / 2;

    Shape.setPosition(sf::Vector2f(X, Y));

    Window.draw(Shape);
}
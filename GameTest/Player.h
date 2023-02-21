#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(sf::Vector2f Size, const sf::Color& Color = sf::Color::White);

    void Update(int MouseY, int BorderHeight, sf::RenderWindow& Window);

    sf::Vector2f GetPosition() { return Shape.getPosition(); }
    sf::Vector2f GetSize() { return Shape.getSize(); }

private:
    sf::RectangleShape Shape;
};


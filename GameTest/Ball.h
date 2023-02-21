#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Random.h"
#include "Score.h"

class Ball
{
public:
    Ball(float Speed, float Radius, float BorderWidth, float BorderHeight, const sf::Color& Color = sf::Color::White);

    void Update(sf::Vector2f PlayerPosition, float PlayerHeight, sf::RenderWindow& Window, Score* HitScore = nullptr);

private:
    float Speed;
    float Radius;
    sf::CircleShape Shape;
    sf::Vector2f MoveDirection;

    bool CanCollideWithPlayer;

    sf::SoundBuffer HitSoundBuffer;
    sf::Sound HitSound;

    float BorderWidth;
    float BorderHeight;

    sf::Vector2f GetStartDirection();

    void Move();

    bool CheckBorderCollision(int BorderWidth, int BorderHeight);

    bool CheckPlayerCollision(sf::Vector2f PlayerPosition, float PlayerHeight);
};


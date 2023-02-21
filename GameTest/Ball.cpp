#include "Ball.h"

Ball::Ball(float Speed, float Radius, float BorderWidth, float BorderHeight, const sf::Color& Color)
{
    this->Speed = Speed;
    this->Radius = Radius;
    this->CanCollideWithPlayer = true;
    this->BorderWidth = BorderWidth;
    this->BorderHeight = BorderHeight;

    Shape.setRadius(Radius);
    Shape.setFillColor(Color);
    Shape.setOutlineColor(sf::Color::White);
    Shape.setOutlineThickness(2.5f);
    Shape.setPosition(BorderWidth / 2, BorderHeight / 2);

    HitSoundBuffer.loadFromFile("hit.wav");
    HitSound.setBuffer(HitSoundBuffer);

    MoveDirection = GetStartDirection();
}

void Ball::Update(sf::Vector2f PlayerPosition, float PlayerHeight, sf::RenderWindow& Window, Score* HitScore)
{
    Move();

    if (CheckBorderCollision(BorderWidth, BorderHeight))
    {
        HitSound.play();
    }
    if (CheckPlayerCollision(PlayerPosition, PlayerHeight))
    {
        if (HitScore)
        {
            HitScore->IncrementScore();
        }

        HitSound.play();
    }

    Window.draw(Shape);
    Window.draw(HitScore->GetText());
}

sf::Vector2f Ball::GetStartDirection()
{
    Random NumberGenerator;
    float Angle = NumberGenerator.GetRandomNumber(-360.0f, 360.0f);

    float X = Shape.getPosition().x + cos(Angle);
    float Y = Shape.getPosition().y + sin(Angle);

    return sf::Vector2f(X - Shape.getPosition().x, Y - Shape.getPosition().y);
}

void Ball::Move()
{
    Shape.move(MoveDirection * Speed);
}

bool Ball::CheckBorderCollision(int BorderWidth, int WindowHeight)
{
    if (Shape.getPosition().y <= -Radius / 2
        || Shape.getPosition().y >= WindowHeight - Radius * 2)
    {
        MoveDirection.y *= -1;
        CanCollideWithPlayer = true;
        return true;
    }

    if (Shape.getPosition().x >= BorderWidth - Radius * 2)
    {
        MoveDirection.x *= -1;
        CanCollideWithPlayer = true;
        return true;
    }

    return false;
}

bool Ball::CheckPlayerCollision(sf::Vector2f PlayerPosition, float PlayerHeight)
{
    if (CanCollideWithPlayer)
    {
        float PlayerX = PlayerPosition.x;
        float PlayerY = PlayerPosition.y;

        if (Shape.getPosition().y >= PlayerY - Radius
            && Shape.getPosition().y <= PlayerY + PlayerHeight
            && Shape.getPosition().x <= PlayerX + Radius
            && Shape.getPosition().x >= PlayerX)
        {
            MoveDirection.x *= -1;
            CanCollideWithPlayer = false;
            return true;
        }
    }

    if (Shape.getPosition().x <= -Radius * 2)
    {
        MoveDirection.x = 0;
        MoveDirection.y = 0;
    }

    return false;
}
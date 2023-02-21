#include "Score.h"
#include <iostream>

Score::Score(sf::Vector2f ScorePosition, const sf::Color& Color)
{
	Font.loadFromFile("arial.ttf");

	HitScore = 0;

	Text.setFont(Font);
	Text.setString("0");
	Text.setCharacterSize(48);
	Text.setFillColor(Color);
	Text.setOutlineColor(sf::Color::White);
	Text.setOutlineThickness(2.5f);
	Text.setPosition(ScorePosition);
}

void Score::IncrementScore()
{
	Text.setString(std::to_string(++HitScore));
}

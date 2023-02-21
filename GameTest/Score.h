#pragma once

#include <SFML/Graphics.hpp>

class Score
{
private:
	sf::Font Font;
	sf::Text Text;
	int HitScore;

public:
	Score(sf::Vector2f ScorePosition, const sf::Color& Color = sf::Color::White);
	
	void IncrementScore();

	const sf::Text& GetText() { return Text; }
};


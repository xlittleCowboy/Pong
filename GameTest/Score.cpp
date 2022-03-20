#include "Score.h"
#include <iostream>

Score::Score(float window_width)
{
	loadFont();
	score = 0;

	text.setFont(font);
	text.setString("0");
	text.setCharacterSize(48);
	text.setFillColor(Color::White);
	text.setPosition(window_width / 2, 10);
}

void Score::loadFont()
{
	font.loadFromFile("arial.ttf");
}

void Score::updateScore()
{
	text.setString(std::to_string(++score));
}

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Score
{
private:
	Font font;

public:
	Text text;
	int score;
	Score(float window_width);
	void loadFont();
	void updateScore();
};


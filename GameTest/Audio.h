#pragma once

#include <SFML/Audio.hpp>

using namespace sf;

class Audio
{
private:
	SoundBuffer buffer;
	Sound sound;

public:
	Audio();

	void playSound();
};


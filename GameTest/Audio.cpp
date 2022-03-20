#include "Audio.h"

Audio::Audio()
{
	buffer.loadFromFile("hit.wav");
	sound.setBuffer(buffer);
}

void Audio::playSound()
{
	sound.play();
}

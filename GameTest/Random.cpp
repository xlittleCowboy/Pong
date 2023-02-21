#pragma once

#include "Random.h"

float Random::GetRandomNumber(float From, float To)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> distribution(From, To);
	return distribution(mt);
}

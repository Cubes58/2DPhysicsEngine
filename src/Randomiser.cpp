#include "Randomiser.h"

Randomiser::Randomiser()
{
	instance = new Randomiser();
	created = true;
	srand((int)time(NULL));
}

Randomiser * Randomiser::getInstance()
{
	if (created)
	{
		return instance;
	}
	else
	{
		return new Randomiser();
	}
}

int Randomiser::getRand(int lower, int upper)
{
	double scalar = rand() / RAND_MAX;
	double result = lower + (upper - lower) * scalar;
	return (int) result;
}

float Randomiser::getRand(float lower, float upper)
{
	double scalar = rand() / RAND_MAX;
	double result = lower + (upper - lower) * scalar;
	return (float)result;
}

double Randomiser::getRand(double lower, double upper)
{
	double scalar = rand() / RAND_MAX;
	double result = lower + (upper - lower) * scalar;
	return result;
}

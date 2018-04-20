#pragma once

#include <time.h>
#include <cstdlib>


class Randomiser {
private:
	Randomiser();
	static Randomiser * instance;
	static bool created;
public:
	static Randomiser * getInstance();
	int getRand(int lower, int upper);
	float getRand(float lower, float upper);
	double getRand(double lower, double upper);
};

#pragma once

#include <time.h>
#include <cstdlib>

class Randomiser {
private:
	Randomiser();
	~Randomiser();
public:
	static Randomiser &getInstance();
	int getRand(int p_Min, int p_Max);
	float getRand(float p_Min, float p_Max);
	double getRand(double p_Min, double p_Max);
};
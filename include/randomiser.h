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

	// Delete the copy and assignment operators.
	Randomiser(Randomiser const&) = delete;
	Randomiser& operator=(Randomiser const&) = delete;
};
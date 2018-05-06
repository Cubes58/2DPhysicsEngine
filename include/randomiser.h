/**
@file Randomiser.h
*/
#pragma once

#include <time.h>
#include <cstdlib>

class Randomiser {
private:
	Randomiser(); //!< Constructor.
	~Randomiser(); //!< Destructor.
public:
	static Randomiser &getInstance(); //!< Returns an instance of the Randomiser class, to use.
	int getRand(int p_Min, int p_Max); //!< Returns a random integer, between two numbers.
	float getRand(float p_Min, float p_Max); //!< Returns a random float, between two numbers.
	double getRand(double p_Min, double p_Max); //!< Returns a random double, between two numbers.

	// Delete the copy and assignment operators.
	Randomiser(Randomiser const&) = delete; //!< Copy operator.
	Randomiser& operator= (Randomiser const&) = delete; //!< Assignment operator. 
};
/**
@file Randomiser.h
@brief A class that generates random numbers when needed.
*/
#pragma once

#include <time.h>
#include <cstdlib>

/*! \class Randomiser
	\brief A class that generates random numbers when needed.
*/

class Randomiser {
private:
	Randomiser(); //!< Constructor.
	~Randomiser(); //!< Destructor.
public:
	static Randomiser &getInstance(); //!< Returns an instance of the Randomiser class, to use.

	/*!
		\brief Returns a random integer, between two numbers.
		\param p_Min the minimum threshold of the randomly generated number.
		\param p_Max the maximum threshold of the randomly generated number.
		\return returns a pseudo random number between two the specified numbers.
	*/
	int getRand(int p_Min, int p_Max);

	/*!
		\brief Returns a random float, between two numbers.
		\param p_Min the minimum threshold of the randomly generated number.
		\param p_Max the maximum threshold of the randomly generated number.
		\return returns a pseudo random number between two the specified numbers.
	*/
	float getRand(float p_Min, float p_Max);

	/*!
		\brief Returns a random double, between two numbers.
		\param p_Min the minimum threshold of the randomly generated number.
		\param p_Max the maximum threshold of the randomly generated number.
		\return returns a pseudo random number between two the specified numbers.
	*/
	double getRand(double p_Min, double p_Max);

	// Delete the copy and assignment operators.
	Randomiser(Randomiser const&) = delete; //!< Copy operator.
	Randomiser& operator= (Randomiser const&) = delete; //!< Assignment operator. 
};
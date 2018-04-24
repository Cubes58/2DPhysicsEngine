#include "Randomiser.h"

Randomiser::Randomiser() {
	srand((int)time(NULL));
}

Randomiser::~Randomiser() {

}

Randomiser &Randomiser::getInstance() {
	static Randomiser instance;

	return instance;	
}

int Randomiser::getRand(int p_Min, int p_Max) {
	double scalar = (double)rand() / RAND_MAX;
	double result = p_Min + (double)(p_Max - p_Min) * scalar;
	return (int)result;
}

float Randomiser::getRand(float p_Min, float p_Max) {
	double scalar = (double)rand() / RAND_MAX;
	double result = p_Min + (double)(p_Max - p_Min) * scalar;
	return (float)result;
}

double Randomiser::getRand(double p_Min, double p_Max) {
	double scalar = (double)rand() / RAND_MAX;
	double result = p_Min + (double)(p_Max - p_Min) * scalar;
	return result;
}

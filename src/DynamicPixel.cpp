#include "DynamicPixel.h"

DynamicPixel::DynamicPixel(Vector2D<unsigned int> p_Position) : 
	DynamicPixel(p_Position, 1, 1) {

}

DynamicPixel::DynamicPixel(Vector2D<unsigned int> p_Position, Vector2D<float> p_Velocity) : 
	DynamicPixel(p_Position, p_Velocity, 1) {

}

DynamicPixel::DynamicPixel(Vector2D<unsigned int> p_Position, Vector2D<float> p_Velocity, Vector2D<float> p_Acceleration) : 
	m_Position(p_Position), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration) {

}
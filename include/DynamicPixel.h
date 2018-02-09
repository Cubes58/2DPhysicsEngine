#pragma once

#include "Vector2D.h"

class DynamicPixel {
private:
	Vector2D<unsigned int> m_Position;
	Vector2D<float> m_Velocity;
	Vector2D<float> m_Acceleration;
	Vector2D<float> m_PreviousPosition;

	float m_Colour;
	float m_Friction;
	float m_Restitution;
public:
	DynamicPixel(Vector2D<unsigned int> p_Position);
	DynamicPixel(Vector2D<unsigned int> p_Position, Vector2D<float> p_Velocity);
	DynamicPixel(Vector2D<unsigned int> p_Position, Vector2D<float> p_Velocity, Vector2D<float> p_Acceleration);
};
#pragma once

#include "Vector2D.h"

class DynamicPixel {
private:
	Vector2D<float> m_Position;
	Vector2D<float> m_Velocity;
	Vector2D<float> m_Acceleration;
	Vector2D<float> m_PreviousPosition;

	float m_Colour;
	float m_Friction;
	float m_Restitution;
public:
	DynamicPixel();

};
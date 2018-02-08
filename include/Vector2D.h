#pragma once

#include <math.h>

template<class T>

class Vector2D {
protected:
	T m_x;
	T m_y;
public:
	Vector2D() : m_x(T(0)), m_y(T(0)) {
		
	}

	Vector2D(const T &p_Values) { 
		m_x = p_Values; m_y = p_Values; 
	}

	Vector2D(const T &p_X, const T &p_Y) { 
		m_x = p_X; m_y = p_Y; 
	}

	void setX(const T &p_X) { 
		m_x = p_X; 
	}

	void setY(const T &p_Y) { 
		m_y = p_Y; 
	}

	void set(const T &p_X, const T &p_Y) { 
		m_x = p_X; m_y = p_Y; 
	}

	void set(const Vector2D& p_Values) { 
		m_x = p_Values.m_x; m_y = p_Values.m_y; 
	}

	T x() const { 
		return m_x; 
	}

	T y() const { 
		return m_y; 
	}

	Vector2D operator+(const Vector2D &p_Values) const { 
		return Vector2D(m_x + p_Values.m_x, m_y + p_Values.m_y); 
	}

	Vector2D operator-(const Vector2D &p_Values) const { 
		return Vector2D(m_x - p_Values.m_x, m_y - p_Values.m_y); 
	}

	Vector2D operator*(const Vector2D &p_Values) const { 
		return Vector2D(m_x * p_Values.m_x, m_y * p_Values.m_y); 
	}

	Vector2D operator/(const Vector2D &p_Values) const { 
		return Vector2D(m_x / p_Values.m_x, m_y / p_Values.m_y); 
	}

	void operator=(const Vector2D& p_Values) { 
		m_x = p_Values.m_x; m_y = p_Values.m_y; 
	}

	bool operator==(const Vector2D& p_Values) const { 
		return ((m_x == p_Values.m_x) && (m_y == p_Values.m_y)); 
	}

	bool operator!=(const Vector2D& p_Values) const { 
		return !((m_x == p_Values.m_x) && (m_y == p_Values.m_y)); 
	}

	// Negate both the x and y values.
	Vector2D operator-() const { 
		return Vector2D(-m_x, -m_y); 
	}

	// Scale both the x and y values.
	Vector2D operator*(const T& p_Scalar) const { 
		return Vector2D(m_x * p_Scalar, m_y * p_Scalar); 
	}

	Vector2D operator/(const T& p_Scalar) const { 
		return Vector2D(m_x / p_Scalar, m_y / p_Scalar); 
	}

	T dotProduct(const Vector2D& p_Values) const { 
		return ((m_x * p_Values.m_x) + (m_y * p_Values.m_y)); 
	}

	T crossProduct(const Vector2D& p_Values) const { 
		return ((m_x * p_Values.m_y) - (m_y * p_Values.m_x)); 
	}

	T magnitude() const { 
		return sqrt(m_x * m_x + m_y * m_y); 
	}

	Vector2D normal() const { 
		return Vector2D(m_x / magnitude(), m_y / magnitude()); 
	}

	Vector2D perpendicular() const { 
		return Vector2D(m_y, -m_x); 
	}
};
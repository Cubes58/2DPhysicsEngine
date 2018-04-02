#pragma once

enum class MouseButton : unsigned int { 
	LEFT, 
	RIGHT, 
	WHEEL 
};

class MouseClickEvent {
private:
	MouseButton m_MouseButton;
	int m_XPosition;
	int m_YPosition;
public:
	MouseClickEvent() = default;
	MouseClickEvent(MouseButton p_MouseButton, int p_XPosition, int p_YPosition);

	MouseButton getButton();
	int getXPosition();
	int getYPosition();
};
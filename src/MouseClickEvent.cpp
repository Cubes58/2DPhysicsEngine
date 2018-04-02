#include "MouseClickEvent.h"

MouseClickEvent::MouseClickEvent(MouseButton p_MouseButton, int p_XPosition, int p_YPosition) : 
	m_MouseButton(p_MouseButton), m_XPosition(p_XPosition), m_YPosition(p_YPosition)  {
	
}

MouseButton MouseClickEvent::getButton() {
	return m_MouseButton;
}

int MouseClickEvent::getXPosition() {
	return m_XPosition;
}

int MouseClickEvent::getYPosition() {
	return m_YPosition;
}
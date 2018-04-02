#pragma once

#include <string>

#include "MouseClickEvent.h"

class MouseClickObserver {
private:
	static const unsigned int s_m_NumberOfMouseButtons = 3;
public:
	std::string m_ButtonText[s_m_NumberOfMouseButtons] = { "Left", "Right", "Wheel" };
	virtual void update(MouseClickEvent p_State) = 0;
};
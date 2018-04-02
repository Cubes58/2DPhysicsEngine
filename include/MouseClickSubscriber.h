#pragma once

#include <vector>
#include <algorithm>

#include "MouseClickObserver.h"

class MouseClickSubscriber {
private:
	std::vector<MouseClickObserver*> m_Observers;
public:
	void attach(MouseClickObserver *p_Observer);
	void dettach(MouseClickObserver *p_Observer);
	void notify(MouseClickEvent p_UpdatedState);
};
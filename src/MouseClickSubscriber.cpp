#include "MouseClickSubscriber.h"

void MouseClickSubscriber::attach(MouseClickObserver *p_Observer) {
	m_Observers.push_back(p_Observer);
}

void MouseClickSubscriber::dettach(MouseClickObserver *p_Observer) {
	m_Observers.erase(std::remove(m_Observers.begin(), m_Observers.end(), p_Observer), m_Observers.end());
}

void MouseClickSubscriber::notify(MouseClickEvent p_UpdatedState) {
	for (auto &observer : m_Observers) {
		observer->update(p_UpdatedState);
	}
}
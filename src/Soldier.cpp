#include "Soldier.h"

Soldier::Soldier() {

}

Soldier::~Soldier() {

}

void Soldier::update(sf::Time p_DeltaTime) {

}

void Soldier::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	//sf::Sprite s;
	
	p_Target.draw(m_SoldierRectangle);
}

sf::Vector2f Soldier::getPosition() {
	return m_Position;
}

sf::Vector2f Soldier::getSize() {
	return static_cast<sf::Vector2f>(m_SoldierRectangle.getSize());
}
#include "Rocket.h"

Rocket::Rocket(sf::Vector2f p_Position, sf::Vector2f p_Size, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration)
	: DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration) {

}

Rocket::~Rocket() {

}

void Rocket::update(float p_DeltaTime) {

}

void Rocket::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {

	p_Target.draw(m_Shape);
}
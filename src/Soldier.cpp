#include "Soldier.h"

Soldier::Soldier(sf::Vector2f p_Position, sf::Vector2f p_Size, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) 
	: DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration) {
	
	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_Shape.setTexture(TextureManager::instance().getTexture("Soldier"));
	m_Shape.setPosition(m_Position);
}

Soldier::~Soldier() {

}

void Soldier::update(MouseClickEvent p_State) {
	std::cout << "Mouse button " << m_ButtonText[(int)p_State.getButton()] << std::endl;
	std::cout << "X Position: " << p_State.getXPosition() << std::endl;
	std::cout << "Y Position: " << p_State.getYPosition() << std::endl;
	if (p_State.getButton() == MouseButton::LEFT) {
		// Make player jump. 
		float yDifference = m_Position.y - p_State.getYPosition();

		sf::Vector2f initialVelocity;	/* Sqrt-u = 2 * A * -y */
		initialVelocity.y = -std::sqrt(2 * -m_Acceleration.y * -yDifference);

		// Now calculate the time.
		float time = -initialVelocity.y / m_Acceleration.y;

		// Now calculate the X speed -: speed = Distance / Time.
		m_Velocity.x = yDifference / time;

		if (p_State.getXPosition() < m_Position.x) {
			m_Velocity.x = -m_Velocity.x;
		}

		m_Velocity.y = initialVelocity.y;

		// If the mouse click is below the object don't move it, set velocity to 0.
		if (p_State.getYPosition() > m_Position.y) {
			m_Velocity.x = 0;
			m_Velocity.y = 0;
		}
	}
	else if (p_State.getButton() == MouseButton::RIGHT) {
		// Fire a bullet.

	}
	else {
		// Do something for the mouse wheel, input.
	}
}

void Soldier::update(float p_DeltaTime) {
	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_Shape.setPosition(m_Position);

	m_Acceleration.x = 0.0f;
	m_Acceleration.y = 98.1f;
}

void Soldier::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Shape);
}
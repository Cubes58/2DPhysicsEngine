#include "Soldier.h"

Soldier::Soldier(const Team &p_Team, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size,
	const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration)
	: DynamicObject(p_Position, p_Gravity, p_Size, p_Velocity, p_Acceleration), PixelPerfectObject(p_Position, *TextureManager::instance().getTexture("Soldier")), 
	m_Health(100.0f), m_Team(p_Team) {
	
	m_Shape.setTexture(TextureManager::instance().getTexture("Soldier"));
	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(sf::Vector2f(m_Size.x / 2, m_Size.y / 2));
	m_Shape.setPosition(m_Position);
}

Soldier::~Soldier() {

}

void Soldier::jump(const sf::Vector2f &p_MousePosition) {
	// Make player jump. 
	float yDifference = m_Position.y - p_MousePosition.y;

	sf::Vector2f initialVelocity;	/* Sqrt-u = 2 * A * -y */
	initialVelocity.y = -std::sqrt(2 * -m_Acceleration.y * -yDifference);

	// Now calculate the time.
	float time = -initialVelocity.y / m_Acceleration.y;
	m_Velocity.y = initialVelocity.y;

	// Now calculate the X speed -: speed = Distance / Time.
	m_Velocity.x = yDifference / time;

	if (p_MousePosition.x < m_Position.x) {
		m_Velocity.x = -m_Velocity.x;
	}

	// If the mouse click is below the object don't move it, set velocity to 0.
	if (p_MousePosition.y > m_Position.y) {
		m_Velocity.x = 0;
		m_Velocity.y = 0;
	}
}

void Soldier::shoot(const sf::Vector2f &p_MousePosition) {
	// Create a bomb.
	float yDifference = m_Position.y - p_MousePosition.y;

	sf::Vector2f initialVelocity;	/* Sqrt-u = 2 * A * -y */
	initialVelocity.y = -std::sqrt(2 * -m_Acceleration.y * -yDifference);

	float time = -initialVelocity.y / m_Acceleration.y;
	// Now calculate the X speed -: speed = Distance / Time.
	sf::Vector2f bombVelocity;
	bombVelocity.x = yDifference / time;

	if (p_MousePosition.x < m_Position.x) {
		bombVelocity.x = -bombVelocity.x;
	}

	bombVelocity.y = initialVelocity.y;

	// If the mouse click is below the object don't move it, set velocity to 0.
	if (p_MousePosition.y > m_Position.y) {
		bombVelocity.x = 0;
		bombVelocity.y = 0;
	}

	sf::Vector2f bombSize = sf::Vector2f(25, 25);
	m_Bomb = std::make_shared<Bomb>(m_Team, m_Position, m_Gravity, bombSize, bombVelocity);
}

void Soldier::processKeyPress(const sf::Event &p_Event, int &p_PlayerCounter) {
	switch(p_Event.key.code) {
	case sf::Mouse::Left:
		p_PlayerCounter++;
		jump(sf::Vector2f((float)p_Event.mouseButton.x, (float)p_Event.mouseButton.y));
		break;
	case sf::Mouse::Right:
		p_PlayerCounter++;
		shoot(sf::Vector2f((float)p_Event.mouseButton.x, (float)p_Event.mouseButton.y));
		break;
	case sf::Mouse::Middle:
		// Do something for the mouse wheel, input. (Move directly up, and then to the left or right or fire?)
		break;
	}
}

void Soldier::update(float p_DeltaTime) {
	// Update the soldier.
	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_Shape.setPosition(m_Position);
	if (m_GravityOn) {
		m_Acceleration.x = m_Gravity.x;
		m_Acceleration.y = m_Gravity.y;
	}

	if(m_Bomb != nullptr && m_Bomb->getDeleteMe()) {
		m_Bomb = nullptr;
	}
}

void Soldier::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Shape);
}

std::shared_ptr<Bomb> Soldier::getBomb() {
	return m_Bomb;
}

 float Soldier::getHealth() {
	 return m_Health;
 }
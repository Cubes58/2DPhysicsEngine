#include "Soldier.h"

const float Soldier::m_s_ScoreForKillingSoldier = 305.2f;
const float Soldier::m_s_ScoreForHittingSoldier = 155.0f;
const float Soldier::m_s_ScoreForHittingTerrain = 33.5f;

Soldier::Soldier(const Team &p_Team, const sf::Texture &p_Texture, const sf::Vector2f &p_Position, 
	const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration)
	: DynamicObject(p_Position, p_Gravity, p_Size, p_Velocity, p_Acceleration), PixelPerfectObject(p_Position, p_Texture), 
	m_Health(100.0f), m_Team(p_Team), m_Score(0.0f), m_Lives(1) {
	
	m_Shape.setTexture(&p_Texture);
	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(sf::Vector2f(m_Size.x / 2.0f, m_Size.y / 2.0f));
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
		m_Velocity.x = 0.0f;
		m_Velocity.y = 0.0f;
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
		bombVelocity.x = 0.0f;
		bombVelocity.y = 0.0f;
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

	if (m_Position.x < 0 || m_Position.x > 1280) {
		setVelocity(sf::Vector2f(-m_Velocity.x, m_Velocity.y));
	}
	if (m_Position.y < m_Size.y / 2) {
		setVelocity(sf::Vector2f(m_Velocity.x, -m_Velocity.y));
	}

	if (m_Position.y > 720) {
		m_Lives--;
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

int Soldier::getLives() {
	return m_Lives;
}

void Soldier::setLives(int p_Lives) {
	m_Lives = p_Lives;
}

float Soldier::getHealth() {
	 return m_Health;
}

void Soldier::setHealth(float p_Health) {
	m_Health = p_Health;
}

Team Soldier::getTeam() {
	 return m_Team;
}

 float Soldier::getScore() {
	 return m_Score;
}
void Soldier::setScore(float p_Score) {
	m_Score = p_Score;
}

void Soldier::addScore(float p_AddScore) {
	m_Score += p_AddScore;
}
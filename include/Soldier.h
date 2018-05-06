#pragma once

#include <cmath>
#include <memory>

#include "TextureManager.h"
#include "DynamicObject.h"
#include "Bomb.h"
#include "Team.h"

class Soldier : public DynamicObject, public PixelPerfectObject {
private:
	std::shared_ptr<Bomb> m_Bomb;

	int m_Lives;
	float m_Score;
	float m_Health;
	Team m_Team;

	void jump(const sf::Vector2f &p_MousePosition);
	void shoot(const sf::Vector2f &p_MousePosition);
public:
	Soldier(const Team &p_Team, const sf::Texture &p_Texture, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size,
		const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f));
	~Soldier();
	
	const static float m_s_ScoreForHittingSoldier;
	const static float m_s_ScoreForHittingTerrain;

	void processKeyPress(const sf::Event &p_Event, int &p_PlayerCounter);
	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	std::shared_ptr<Bomb> getBomb();

	Team getTeam();

	int getLives();
	void setLives(int p_Lives);

	float getScore();
	void setScore(float p_Score);
	void addScore(float p_AddScore);

	float getHealth();
	void setHealth(float p_Health);
};
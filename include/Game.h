#pragma once

#include <SFML\Graphics.hpp>

class Game : public sf::Drawable {
private:	
	bool m_bIsRunning;
public:
	Game();
	~Game();

	void processKeyPress(sf::Keyboard::Key p_Key);
	void processKeyRelease(sf::Keyboard::Key p_Key);

	void update(sf::Time p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool isRunning();
	void setRunningState(bool p_bRunningState);
};
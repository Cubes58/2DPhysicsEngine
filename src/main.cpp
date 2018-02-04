#include "Game.h"

int main() {
	const int kiWidth = 480;
	const int kiHeight = 480;

	sf::RenderWindow window(sf::VideoMode(kiWidth, kiHeight), "Blaster", sf::Style::Default);
	Game game;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (game.isRunning()) {
		window.clear(sf::Color::Black);
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				game.setRunningState(false);
				break;
			case sf::Event::KeyPressed:
				game.processKeyPress(event.key.code);
				break;
			case sf::Event::KeyReleased:
				game.processKeyRelease(event.key.code);
				break;
			default:
				continue;
			}
		}

		while (timeSinceLastUpdate >= timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			game.update(timePerFrame);
		}
		//window.clear(sf::Color::Black);
		window.draw(game);		
		window.display();
	}

	return EXIT_SUCCESS;
}
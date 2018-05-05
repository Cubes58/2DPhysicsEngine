#include "Game.h"
#include "Randomiser.h"

int main() {
	const int kiWidth = 1280;
	const int kiHeight = 720;

	sf::RenderWindow window(sf::VideoMode(kiWidth, kiHeight), "Blaster", sf::Style::Default);
	Game game;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
 	while (game.isRunning()) {
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
			case sf::Event::MouseButtonPressed:
				game.processKeyPress(event);
				break;
			case sf::Event::KeyReleased:
			case sf::Event::MouseButtonReleased:
				game.processKeyRelease(event);
				break;
			default:
				continue;
			}
		}

		while (timeSinceLastUpdate >= timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			game.update(timePerFrame.asSeconds());
		}
		window.clear(sf::Color::Black);
		window.draw(game);
		window.display();
	}

	return EXIT_SUCCESS;
}
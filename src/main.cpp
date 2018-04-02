#include "Game.h"

int main() {
	const int kiWidth = 1280;
	const int kiHeight = 720;

	sf::RenderWindow window(sf::VideoMode(kiWidth, kiHeight), "Blaster", sf::Style::Default);
	Game game;	// Might pass it the game view, or have it in there?
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::View gameView;
	gameView.setCenter(sf::Vector2f(960, 600));
	gameView.setSize(sf::Vector2f(1920, 1200));
	window.setView(gameView);

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
		window.draw(game);		
		window.display();
	}

	return EXIT_SUCCESS;
}
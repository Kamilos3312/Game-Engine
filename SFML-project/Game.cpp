#include "Game.hpp"

Game::Game() {

	window.create(sf::VideoMode(430, 700, 32), "[SFML] Simple Game Engine", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	window.setKeyRepeatEnabled(false);

	try {
		loadResources();
		cursor = Cursor(resourceManager.getTexture("cursor"));
	}
	catch (std::string e) {
		Debug::Log("Error", e);
	}
	window.setIcon(resourceManager.getImage("icon").getSize().x, resourceManager.getImage("icon").getSize().y, resourceManager.getImage("icon").getPixelsPtr());

	volume = 50;
}

void Game::mainLoop() {

	stateManager.pushState(new StateInit(this));
	sf::Clock clock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {

		deltaTime = clock.restart().asSeconds();

		//while (logic timestep stuff) {
			sf::Event event;
			while (window.pollEvent(event)) {
				handleEvent(event);
			}
			update(deltaTime);
		//}

		draw();
	}
}

void Game::handleEvent(sf::Event &_event) {

	if (_event.type == sf::Event::Closed)
		window.close();

	if (_event.key.code == sf::Keyboard::Add) {
		if (volume < 100) {
			volume++;
			stateManager.peekState()->setVolume();
		}
	}
	else if (_event.key.code == sf::Keyboard::Subtract) {
		if (volume > 0) {
			volume--;
			stateManager.peekState()->setVolume();
		}
	}

	stateManager.peekState()->handleEvent(_event);
}

void Game::update(float deltaTime) {

	cursor.update(sf::Mouse::getPosition(window));
	stateManager.peekState()->update(deltaTime);
}

void Game::draw() {

	window.clear();
	stateManager.peekState()->draw(window);
	window.draw(cursor);
	window.display();
}

void Game::loadResources() {
	resourceManager.addFont("LemonMilk",				"resources/font/LemonMilk.otf");

	resourceManager.addImage("icon",					"resources/img/icon.png");

	resourceManager.addTexture("cursor",				"resources/img/cursor.png");
	resourceManager.addTexture("background",			"resources/img/background.jpg");
	resourceManager.addTexture("logo",					"resources/img/logo.png");
	resourceManager.addTexture("logo2",					"resources/img/logo2.png");
	resourceManager.addTexture("button",				"resources/img/button.png");
	resourceManager.addTexture("button-hover",			"resources/img/button_hover.png");

	resourceManager.addSound("menu-theme",				"resources/sfx/menu_theme.ogg");
}
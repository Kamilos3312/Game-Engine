#pragma once

#include "StateManager.hpp"
#include "ResourceManager.hpp"
// Load App states
#include "States/StateInit.hpp"
#include "States/StateMenu.hpp"
#include "States/StateGame.hpp"
#include "States/StateCredit.hpp"

#include "Addons/Cursor.hpp"
#include "Addons/Debug.hpp"

#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	~Game() = default;

	void mainLoop();

public:
	sf::RenderWindow window;
	Cursor cursor;

	StateManager stateManager;
	ResourceManager resourceManager;

	unsigned int volume;

private:
	void handleEvent(sf::Event &_event);
	void update(float elapsedTime);
	void draw();

	void loadResources();
};
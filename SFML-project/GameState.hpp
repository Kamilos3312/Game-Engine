#pragma once
#include <SFML/Graphics.hpp>

class Game;

class GameState {
public:
	virtual void handleEvent(sf::Event &_event) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

	virtual void playMusic() = 0;
	virtual void stopMusic() = 0;
	virtual void setVolume() = 0;

	Game* game;
};
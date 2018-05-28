#pragma once

#include "../GameState.hpp"

class StateInit : public GameState {
public:
	StateInit(Game* game);
	~StateInit();

	void handleEvent(sf::Event &_event) override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow &window) override;

	void playMusic() override { };
	void stopMusic() override { };
	void setVolume() override { };

private:
	sf::View view;

	sf::Sprite sprite;

	float elapsed;
	unsigned int logoNum;
};
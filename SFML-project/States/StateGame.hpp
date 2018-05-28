#pragma once

#include "../GameState.hpp"
#include "../Addons/Color.hpp"
#include "../Addons/Text.hpp"

#include <SFML/Audio.hpp>

class StateGame : public GameState {
public:
	StateGame(Game* game);
	~StateGame();

	void handleEvent(sf::Event &_event) override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow &window) override;

	void playMusic() override;
	void stopMusic() override;
	void setVolume() override;

private:
	sf::View view;

	sf::Sprite backgroundSprite;
	sf::Sound theme;
};

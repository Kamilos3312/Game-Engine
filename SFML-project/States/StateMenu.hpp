#pragma once

#include "../GameState.hpp"
#include "../Addons/Button.hpp"
#include "../Addons/Color.hpp"
#include "../Addons/Text.hpp"

#include <SFML/Audio.hpp>

class StateMenu : public GameState {
public:
	StateMenu(Game* game);
	~StateMenu();

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

	float elapsed;

	Text title;
	Button startButton, creditsButton, exitButton;
};


#pragma once

#include "../GameState.hpp"
#include "../Addons/Button.hpp"
#include "../Addons/Text.hpp"

class StateCredit : public GameState {
public:
	StateCredit(Game* game);
	~StateCredit();

	void handleEvent(sf::Event &_event) override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow &window) override;

	void playMusic() override { };
	void stopMusic() override { };
	void setVolume() override { };

	void setDescription();

private:
	sf::View view;

	sf::Sprite backgroundSprite;

	Text title;
	sf::Text description[4];
	Button returnButton;
};
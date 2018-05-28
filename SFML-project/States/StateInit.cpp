#include "StateInit.hpp"
#include "../Game.hpp"

StateInit::StateInit(Game* game) {
	Debug::Log("StateInit", "Initializing..");
	this->game = game;

	this->view.setCenter(sf::Vector2f(this->game->window.getSize() / 2u));
	this->view.setSize(sf::Vector2f(this->game->window.getSize()));

	sprite.setTexture(this->game->resourceManager.getTexture("logo"), true);
	sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize() / 2u));
	sprite.setPosition(sf::Vector2f(this->game->window.getSize() / 2u));

	elapsed = 0.0f;
	logoNum = 1;
	Debug::Log("StateInit", "Initialized.");
}


StateInit::~StateInit() {

	Debug::Log("StateInit", "Destroyed.");
}

void StateInit::handleEvent(sf::Event &_event) {

	if (_event.type == sf::Event::KeyReleased) {

		if (_event.key.code == sf::Keyboard::Enter)
			elapsed += 3;
	}
}


void StateInit::update(float deltaTime) {

	this->game->window.setView(view);

	sprite.scale(sf::Vector2f(0.999f, 0.999f));
	elapsed += deltaTime;
	if (elapsed >= 3 && logoNum >= 2)
		this->game->stateManager.changeState(new StateMenu(this->game));
	else if (elapsed >= 3) {
		elapsed = 0.0f;
		logoNum++;
		sprite.setTexture(this->game->resourceManager.getTexture("logo" + std::to_string(logoNum)), true);
		sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize() / 2u));
		sprite.setPosition(sf::Vector2f(this->game->window.getSize() / 2u));
	}
}


void StateInit::draw(sf::RenderWindow & window) {
	window.draw(sprite);
}

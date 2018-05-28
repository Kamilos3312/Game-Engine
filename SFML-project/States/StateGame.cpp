#include "StateGame.hpp"
#include "../Game.hpp"


StateGame::StateGame(Game* game) {
	Debug::Log("StateGame", "Initializing..");
	this->game = game;

	this->view.setCenter(sf::Vector2f(this->game->window.getSize() / 2u));
	this->view.setSize(sf::Vector2f(this->game->window.getSize()));

	backgroundSprite.setTexture(this->game->resourceManager.getTexture("game-background"), true);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundSprite.getTexture()->getSize() / 2u));
	backgroundSprite.setPosition(sf::Vector2f(this->game->window.getSize() / 2u));

	theme.setBuffer(this->game->resourceManager.getSound("game-theme"));
	theme.setVolume(static_cast<float>(this->game->volume));
	theme.play();

	Debug::Log("StateGame", "Initialized.");
}


StateGame::~StateGame() {

	Debug::Log("StateGame", "Destroyed.");
}


void StateGame::handleEvent(sf::Event &_event) {

	// ================================================================
	// ==== Keyboard Events
	if (_event.type == sf::Event::KeyReleased) {

		if (_event.key.code == sf::Keyboard::Escape) {
			theme.stop();
			this->game->stateManager.popState();
			this->game->stateManager.peekState()->playMusic();
		}
	}
}


void StateGame::update(float deltaTime) {

	this->game->window.setView(view);
}


void StateGame::draw(sf::RenderWindow & window) {

	window.draw(backgroundSprite);
}


void StateGame::playMusic() {

	theme.play();
}


void StateGame::stopMusic() {

	theme.stop();
}


void StateGame::setVolume() {

	theme.setVolume(static_cast<float>(this->game->volume));
	Debug::Log("Volume", theme.getVolume());
}
#include "StateMenu.hpp"
#include "../Game.hpp"


StateMenu::StateMenu(Game* game) :
	title(game->resourceManager.getFont("LemonMilk"), "Game Engine", 60, Color::White, sf::Vector2f(float(game->window.getSize().x / 2), float(game->window.getSize().y / 8u))),
	startButton(game->resourceManager.getTexture("button"), game->resourceManager.getTexture("button-hover"), game->resourceManager.getFont("LemonMilk"), "Start", 14u, Color::Peru, sf::Vector2f(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 1.70f)), sf::Vector2f(300.0f, 50.0f)),
	creditsButton(game->resourceManager.getTexture("button"), game->resourceManager.getTexture("button-hover"), game->resourceManager.getFont("LemonMilk"), "Credits", 14u, Color::Peru, sf::Vector2f(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 1.30f)), sf::Vector2f(300.0f, 50.0f)),
	exitButton(game->resourceManager.getTexture("button"), game->resourceManager.getTexture("button-hover"), game->resourceManager.getFont("LemonMilk"), "Exit", 14u, Color::Peru, sf::Vector2f(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 1.10f)), sf::Vector2f(300.0f, 50.0f))
{
	Debug::Log("StateMenu", "Initializing..");
	this->game = game;

	this->view.setCenter(sf::Vector2f(this->game->window.getSize() / 2u));
	this->view.setSize(sf::Vector2f(this->game->window.getSize()));

	backgroundSprite.setTexture(this->game->resourceManager.getTexture("background"), true);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundSprite.getTexture()->getSize() / 2u));
	backgroundSprite.setPosition(sf::Vector2f(this->game->window.getSize() / 2u));

	theme.setBuffer(this->game->resourceManager.getSound("menu-theme"));
	theme.setVolume(static_cast<float>(this->game->volume));
	theme.play();

	elapsed = 0.0f;
	Debug::Log("StateMenu", "Initialized.");
}


StateMenu::~StateMenu() {

	Debug::Log("StateMenu", "Destroyed.");
}


void StateMenu::handleEvent(sf::Event &_event) {

	// ================================================================
	// ==== Mouse Events
	sf::Vector2i mousePosition = sf::Mouse::getPosition(this->game->window);

	if (_event.type == sf::Event::MouseButtonReleased) {
		if (_event.mouseButton.button == sf::Mouse::Left) {
			if (startButton.intersect(mousePosition)) { theme.stop(); game->stateManager.pushState(new StateGame(this->game)); }
			else if (creditsButton.intersect(mousePosition)) { game->stateManager.pushState(new StateCredit(this->game)); }
			else if (exitButton.intersect(mousePosition)) { theme.stop(); this->game->window.close(); }
		}
	}

	if (_event.type == sf::Event::MouseMoved) {
		startButton.hover(startButton.intersect(mousePosition));
		creditsButton.hover(creditsButton.intersect(mousePosition));
		exitButton.hover(exitButton.intersect(mousePosition));
	}
}


void StateMenu::update(float deltaTime) {

	this->game->window.setView(view);
}


void StateMenu::draw(sf::RenderWindow & window) {

	window.draw(backgroundSprite);
	window.draw(title);
	window.draw(startButton);
	window.draw(creditsButton);
	window.draw(exitButton);
}


void StateMenu::playMusic() {

	theme.play();
}


void StateMenu::stopMusic() {

	theme.stop();
}

void StateMenu::setVolume() {

	theme.setVolume(static_cast<float>(this->game->volume));
	Debug::Log("Volume", theme.getVolume());
}
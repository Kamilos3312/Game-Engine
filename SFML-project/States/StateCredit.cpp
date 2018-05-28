#include "StateCredit.hpp"
#include "../Game.hpp"


StateCredit::StateCredit(Game* game) :
	title(game->resourceManager.getFont("LemonMilk"), "Credits", 42u, Color::White, sf::Vector2f(float(game->window.getSize().x / 2u), 42.0f)),
	returnButton(game->resourceManager.getTexture("button"), game->resourceManager.getTexture("button-hover"), game->resourceManager.getFont("LemonMilk"), "Return", 14u, Color::Peru, sf::Vector2f(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 1.10f)), sf::Vector2f(300.0f, 50.0f))
{
	Debug::Log("StateCredit", "Initializing..");

	this->game = game;

	this->view.setCenter(sf::Vector2f(this->game->window.getSize() / 2u));
	this->view.setSize(sf::Vector2f(this->game->window.getSize()));

	backgroundSprite.setTexture(this->game->resourceManager.getTexture("background"), true);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundSprite.getTexture()->getSize() / 2u));
	backgroundSprite.setPosition(sf::Vector2f(this->game->window.getSize() / 2u));

	setDescription();
	Debug::Log("StateCredit", "Initialized.");
}


StateCredit::~StateCredit() {

	Debug::Log("StateCredit", "Destroyed.");
}


void StateCredit::handleEvent(sf::Event &_event) {

	// ================================================================
	// ==== Keyboard Events
	if (_event.type == sf::Event::KeyPressed) {

		// ...
	}
	else if (_event.type == sf::Event::KeyReleased) {

		if (_event.key.code == sf::Keyboard::Escape) {
			this->game->stateManager.popState();
		}
	}

	// ================================================================
	// ==== Mouse Events
	sf::Vector2i mousePosition = sf::Mouse::getPosition(this->game->window);

	if (_event.type == sf::Event::MouseButtonReleased) {
		if (_event.mouseButton.button == sf::Mouse::Left) {
			if (returnButton.intersect(mousePosition)) { this->game->stateManager.popState(); }
		}
	}

	if (_event.type == sf::Event::MouseMoved) {
		returnButton.hover(returnButton.intersect(mousePosition));
	}
}


void StateCredit::update(float deltaTime) {

	this->game->window.setView(view);
}


void StateCredit::draw(sf::RenderWindow & window) {
	
	window.draw(backgroundSprite);
	window.draw(title);
	for (int i = 0; i < 4; i++)
		window.draw(description[i]);
	window.draw(returnButton);
}


void StateCredit::setDescription() {

	description[0].setCharacterSize(36u);
	description[0].setString("Author");
	description[0].setPosition(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 5.5f));

	description[1].setCharacterSize(28u);
	description[1].setString("Kamilos3312");
	description[1].setPosition(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 4u));

	description[2].setCharacterSize(36u);
	description[2].setString("Created with");
	description[2].setPosition(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 2.5f));

	description[3].setCharacterSize(28u);
	description[3].setString("C++ & SFML");
	description[3].setPosition(float(game->window.getSize().x / 2u), float(game->window.getSize().y / 2.15f));

	sf::FloatRect textRect;
	for (int i = 0; i < 4; i++) {
		description[i].setFont(game->resourceManager.getFont("LemonMilk"));
		description[i].setFillColor(Color::Yellow);

		textRect = description[i].getLocalBounds();
		description[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	}
}
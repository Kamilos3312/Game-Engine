#pragma once
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Button : public sf::Drawable {
public:
	Button(const sf::Texture &texture, const sf::Texture &hoverTexture, const sf::Font &font, std::string text, unsigned int characterSize , sf::Color color, sf::Vector2f location, sf::Vector2f size);
	bool intersect(sf::Vector2i);
	void hover(bool hover);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(sprite, states);
		target.draw(text, states);
	}

private:
	sf::Font font;
	sf::Text text;

	sf::Texture texture;
	sf::Texture hoverTexture;
	sf::Sprite sprite;	
};


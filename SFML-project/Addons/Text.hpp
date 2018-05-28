#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Text : public sf::Drawable {
public:
	Text() = default;
	Text(const sf::Font &font, std::string textString, unsigned int characterSize, sf::Color color, sf::Vector2f position) {
		text.setFont(font);
		text.setString(textString);
		text.setCharacterSize(characterSize);
		text.setFillColor(color);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(position);
	}
	Text(const sf::Font &font, std::string textString, unsigned int characterSize, sf::Color color, sf::Vector2f position, float rotation) {
		text.setFont(font);
		text.setString(textString);
		text.setCharacterSize(characterSize);
		text.setFillColor(color);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setRotation(rotation);
		text.setPosition(position);
	}
	~Text() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(text, states);
	}

	void setString(std::string text) { this->text.setString(text); }
	std::string getString() { return this->text.getString(); }
	size_t length() { return this->text.getString().getSize(); }

private:
	sf::Text text;
};
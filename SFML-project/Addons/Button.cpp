#include "Button.hpp"

Button::Button(const sf::Texture &texture, const sf::Texture &hoverTexture, const sf::Font &font, std::string text, unsigned int characterSize, sf::Color color, sf::Vector2f location, sf::Vector2f size) {

	this->texture = texture;
	this->hoverTexture = hoverTexture;
	this->font = font;

	sprite.setTexture(this->texture);
	sprite.setOrigin(size / 2.0f);
	sprite.setPosition(location);

	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(color);
	this->text.setCharacterSize(characterSize);
	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->text.setPosition(sprite.getPosition());
}

bool Button::intersect(sf::Vector2i mousePos) {
	
	if (mousePos.x > sprite.getPosition().x - sprite.getTexture()->getSize().x / 2 && mousePos.x < (sprite.getPosition().x + sprite.getTexture()->getSize().x / 2))
		if (mousePos.y > sprite.getPosition().y - sprite.getTexture()->getSize().y / 2 && mousePos.y < (sprite.getPosition().y + sprite.getTexture()->getSize().y / 2))
			return true;

	return false;
}


void Button::hover(bool hover) {
	
	if (hover) {
		sprite.setTexture(hoverTexture);
	}
	else
		sprite.setTexture(texture);
}

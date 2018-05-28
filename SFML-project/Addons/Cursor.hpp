#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class Cursor : public sf::Drawable {
public:
	Cursor() = default;
	Cursor(const sf::Texture &texture) {

		sprite.setTexture(texture);
	}
	~Cursor() = default;

	void update(sf::Vector2i mousePosition) {
		sprite.setPosition(sf::Vector2f(mousePosition));
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(sprite, states);
	}

private:
	sf::Sprite sprite;
};
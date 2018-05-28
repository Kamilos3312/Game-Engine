#include "ResourceManager.hpp"

ResourceManager::ResourceManager() :
	fonts(), textures(), images()
{
	// ...
}

void ResourceManager::addFont(const std::string key, const std::string filePath) {

	sf::Font font;
	if (!font.loadFromFile(filePath))
		throw "Font " + filePath + " not found or could not be loaded.\n";

	fonts[key] = font;
}

void ResourceManager::addTexture(const std::string key, const std::string filePath) {

	sf::Texture texture;
	if (!texture.loadFromFile(filePath))
		throw "Texture " + filePath + " not found or could not be loaded.\n";

	textures[key] = texture;
}

void ResourceManager::addImage(const std::string key, const std::string filePath) {

	sf::Image image;
	if (!image.loadFromFile(filePath))
		throw "Image " + filePath + " not found or could not be loaded.\n";

	images[key] = image;
}

void ResourceManager::addSound(const std::string key, const std::string filePath) {

	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(filePath))
		throw "Sound " + filePath + " not found or could not be loaded.\n";

	sounds[key] = soundBuffer;
}

const sf::Font& ResourceManager::getFont(const std::string& key) {

	for (auto it = fonts.begin(); it != fonts.end(); ++it) {
		if (key == it->first) {
			return it->second;
		}
	}

	throw "Font with key: " + key + " does not exist.\n";
}

const sf::Texture& ResourceManager::getTexture(const std::string& key) {

	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (key == it->first) {
			return it->second;
		}
	}

	throw "Texture with key: " + key + " does not exist.\n";
}

const sf::Image& ResourceManager::getImage(const std::string& key) {

	for (auto it = images.begin(); it != images.end(); ++it) {
		if (key == it->first) {
			return it->second;
		}
	}

	throw "Font with key: " + key + " does not exist.\n";
}

const sf::SoundBuffer& ResourceManager::getSound(const std::string& key) {

	for (auto it = sounds.begin(); it != sounds.end(); ++it) {
		if (key == it->first) {
			return it->second;
		}
	}

	throw "Sound with key: " + key + " does not exist.\n";
}

void ResourceManager::deleteFont(const std::string& key) {

	auto it = fonts.find(key);
	if (it != fonts.end())
		fonts.erase(it);
}

void ResourceManager::deleteTexture(const std::string& key) {

	auto it = textures.find(key);
	if (it != textures.end())
		textures.erase(it);
}

void ResourceManager::deleteImage(const std::string& key) {

	auto it = images.find(key);
	if (it != images.end())
		images.erase(it);
}

void ResourceManager::deleteSound(const std::string& key) {

	auto it = sounds.find(key);
	if (it != sounds.end())
		sounds.erase(it);
}
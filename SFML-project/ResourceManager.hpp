#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager() = default;

	void addFont(const std::string key, const std::string filePath);
	const sf::Font& getFont(const std::string &key);
	void deleteFont(const std::string& key);

	void addTexture(const std::string key, const std::string filePath);
	const sf::Texture& getTexture(const std::string &key);
	void deleteTexture(const std::string& key);

	void addImage(const std::string key, const std::string filePath);
	const sf::Image& getImage(const std::string &key);
	void deleteImage(const std::string& key);

	void addSound(const std::string key, const std::string filePath);
	const sf::SoundBuffer& getSound(const std::string &key);
	void deleteSound(const std::string& key);

private:
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Image> images;
	std::map<std::string, sf::SoundBuffer> sounds;
};


#pragma once
#include <SFML/Graphics.hpp>

class Explosion	{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	sf::Vector2f position;

	Explosion();
	sf::Sprite getSprite();
	void explosionUpdate();
};

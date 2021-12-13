#pragma once
#include <SFML/Graphics.hpp>

class Explosion	{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::CircleShape explosionShape;

public:
	Explosion();

	sf::Vector2f position;
	sf::CircleShape getExplosionShape();

	void explosionUpdate();
};

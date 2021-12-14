#pragma once
#include <SFML/Graphics.hpp>

class Asteroid {
private:
	float speed;
	sf::Texture asteroidTexture;
	sf::Sprite asteridSprite;
public:
	Asteroid();
	sf::Vector2f position;
	bool goRight;

	sf::Sprite getSprite();
	void move();
	void explode();
	void asteroidUpdate();
};


#pragma once
#include <SFML/Graphics.hpp>

class Asteroid {
private:
	float speed;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Asteroid();
	sf::Vector2f position;
	bool goRight;

	sf::Sprite getSprite();
	void move();
	void explode();
	void update();
};


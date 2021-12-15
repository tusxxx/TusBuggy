#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
	float speed;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	sf::Vector2f position;
	bool goRight;
	bool isExploded;

	Enemy();
	sf::Sprite getSprite();
	void move();
	void explode();
	void update();
};

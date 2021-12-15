#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
public:
	Player();
	sf::Vector2f position;

	sf::Sprite getSprite();
	void moveRight();
	void moveLeft();
	void shoot();
	void update();
};


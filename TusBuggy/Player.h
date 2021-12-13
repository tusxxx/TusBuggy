#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	sf::RectangleShape shapeOflPayer;

	
public:
	Player();
	sf::RectangleShape getSprite();
	sf::Vector2f position;

	void moveRight();
	void moveLeft();
	void shoot();

	void playerUpdate();
};


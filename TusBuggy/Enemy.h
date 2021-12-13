#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
	float speed;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape shapeOfEnemy;
public:
	Enemy();
	sf::RectangleShape getSprite();
	sf::Vector2f position;
	bool goRight;

	void move();
	void explode();
	void enemyUpdate();
};

#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
	float speed;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
public:
	Enemy();
	sf::Vector2f position;
	bool goRight;

	sf::Sprite getSprite();
	void move();
	void explode();
	void enemyUpdate();
};

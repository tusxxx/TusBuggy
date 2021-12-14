#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
private:
	float speed;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

public:
	sf::Vector2f position;
	bool goRight;

	Enemy();
	sf::Sprite getSprite();
	void move();
	void explode();
	void enemyUpdate();
};

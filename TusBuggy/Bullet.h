#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Bullet {
private:
	float speed;

	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;	
	
	bool colliderCheck;

public:
	bool isMove;
	sf::Vector2f position;

	Bullet();
	sf::Sprite getSprite();

	void fly();
	bool checkCollide();

	void bulletUpdate();
};


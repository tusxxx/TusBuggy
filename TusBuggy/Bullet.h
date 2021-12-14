#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Asteroid.h"

class Bullet {
private:
	float speed;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;	

public:
	bool isMove;
	sf::Vector2f position;

	Bullet();
	sf::Sprite getSprite();
	void fly();
	void bulletUpdate();
};


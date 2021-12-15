#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Asteroid.h"

class Bullet {
private:
	float speed;
	sf::Texture texture;
	sf::Sprite sprite;	

public:
	bool isMove;
	sf::Vector2f position;

	Bullet();
	sf::Sprite getSprite();
	void fly();
	void update();
};


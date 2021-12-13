#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Bullet {
private:
	float speed;

	sf::Texture texture;
	sf::Sprite sprite;	
	sf::CircleShape form;
	
	bool colliderCheck;

public:
	sf::Vector2f position;

	Bullet();
	sf::CircleShape getShape();

	void fly();
	bool checkCollide();

	void bulletUpdate();
};


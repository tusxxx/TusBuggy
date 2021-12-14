#include "Bullet.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet() {
	isMove = false;
	speed = 3.5f;
	bulletTexture.loadFromFile("bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(0.8, 0.8);
}

sf::Sprite Bullet::getSprite() {
	return bulletSprite;
}

void Bullet::fly() {
	position.y -= speed;
}

void Bullet::bulletUpdate() {
	bulletSprite.setPosition(position);
}	

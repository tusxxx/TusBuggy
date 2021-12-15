#include "Bullet.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet() {
	isMove = false;
	speed = 3.5f;
	texture.loadFromFile("bullet.png");
	sprite.setTexture(texture);
	sprite.setScale(0.8, 0.8);
}

sf::Sprite Bullet::getSprite() {
	return sprite;
}

void Bullet::fly() {
	position.y -= speed;
}

void Bullet::update() {
	sprite.setPosition(position);
}	

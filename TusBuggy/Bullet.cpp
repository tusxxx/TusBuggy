#include "Bullet.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet() {
	Player player;

	isMove = false;
	speed = 0.3;
	position = sf::Vector2f(10, 10);
	
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

bool Bullet::checkCollide() {
	return false;
}

void Bullet::bulletUpdate() {
	bulletSprite.setPosition(position);
}

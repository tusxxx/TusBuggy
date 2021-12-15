#include "Enemy.h"
#include <SFML/Graphics.hpp>

Enemy::Enemy() {
	speed = 2;
	goRight = true;
	isExploded = false;
	texture.loadFromFile("enemy.png");
	sprite.setTexture(texture);
	sprite.setScale(1.2, 1.2);
}

sf::Sprite Enemy::getSprite() {
	return sprite;
}

void Enemy::move() {
	if (goRight == true) {
		position.x += speed;
	} else {
		position.x -= speed;
	}
	if (isExploded == true) {
		speed = 4;
		position.y += speed;
	}
}

void Enemy::explode() {
}

void Enemy::update() {
	move();
    sprite.setPosition(position);
}

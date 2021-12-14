#include "Enemy.h"
#include <SFML/Graphics.hpp>

Enemy::Enemy() {
	speed = 0.15f;
	goRight = true;
	position = sf::Vector2f(100, 100);

	enemyTexture.loadFromFile("enemy.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(1.2, 1.2);
}

sf::Sprite Enemy::getSprite() {
	return enemySprite;
}

void Enemy::move() {
	if (goRight == true) {
		position.x += speed;
	} else {
		position.x -= speed;
	}
}

void Enemy::explode() {
	position = sf::Vector2f(-100, -100);
}

void Enemy::enemyUpdate() {
	move();
    enemySprite.setPosition(position);
}

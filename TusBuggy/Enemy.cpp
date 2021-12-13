#include "Enemy.h"
#include <SFML/Graphics.hpp>

Enemy::Enemy() {
	speed = 0.15f;
	goRight = true;
	position = sf::Vector2f(100, 100);
	shapeOfEnemy = sf::RectangleShape(sf::Vector2f(10, 10));
	shapeOfEnemy.setFillColor(sf::Color::Magenta);
    /*texture.loadFromFile("moon_buggy.png");
    sprite.setTexture(texture);*/
}

sf::RectangleShape Enemy::getSprite() {
	return shapeOfEnemy;
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
    shapeOfEnemy.setPosition(position);
}

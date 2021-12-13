#include "Player.h"
#include "Bullet.h"

Player::Player() {
	speed = 0.2;
	position.x = 400;
	position.y = 500;
	rect = sf::RectangleShape(sf::Vector2f(10, 10));
	/*texture.loadFromFile("moon_buggy.png");
	sprite.setTexture(texture);*/
}

void Player::playerUpdate() {
	rect.setPosition(position);
}

void Player::moveRight() {
	position.x += speed;
}

void Player::moveLeft() {
	position.x -= speed;
}


void Player::shoot() {
	Bullet bullet;
	bullet.fly();
}

sf::RectangleShape Player::getSprite() {
	return rect;
}
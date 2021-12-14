#include "Player.h"

Player::Player() {
	speed = 0.2;
	position.x = 400;
	position.y = 500;
	shapeOflPayer = sf::RectangleShape(sf::Vector2f(10, 10));
	texture.loadFromFile("playerShip.png");
	sprite.setTexture(texture);
	sprite.setScale(2, 3);
}

void Player::playerUpdate() {
	sprite.setPosition(position);
}

void Player::moveRight() {
	position.x += speed;
}

void Player::moveLeft() {
	position.x -= speed;
}

sf::Sprite Player::getSprite() {
	return sprite;
}
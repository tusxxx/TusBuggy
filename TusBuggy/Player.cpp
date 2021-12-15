#include "Player.h"

Player::Player() {
	speed = 2.5f;
	position = sf::Vector2f(400, 500);
	texture.loadFromFile("playerShip.png");
	sprite.setTexture(texture);
	sprite.setScale(2, 1);
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
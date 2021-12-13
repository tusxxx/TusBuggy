#include "Player.h"

Player::Player() {
	speed = 0.2;
	position.x = 400;
	position.y = 500;
	shapeOflPayer = sf::RectangleShape(sf::Vector2f(10, 10));
	/*texture.loadFromFile("moon_buggy.png");
	sprite.setTexture(texture);*/
	shapeOflPayer.setFillColor(sf::Color::Cyan);
}

void Player::playerUpdate() {
	shapeOflPayer.setPosition(position);
}

void Player::moveRight() {
	position.x += speed;
}

void Player::moveLeft() {
	position.x -= speed;
}

sf::RectangleShape Player::getSprite() {
	return shapeOflPayer;
}
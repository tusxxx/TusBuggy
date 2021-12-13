#include "Bullet.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet() {
	Player player;

	isMove = false;
	speed = 0.3;
	position = sf::Vector2f(10, 10);
	form = sf::CircleShape(2);
	form.setFillColor(sf::Color::Red);
}

sf::CircleShape Bullet::getShape() {
	return form;
}

void Bullet::fly() {
	position.y -= speed;
}

bool Bullet::checkCollide() {
	return false;
}

void Bullet::bulletUpdate() {
	form.setPosition(position);
}

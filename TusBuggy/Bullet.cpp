#include "Bullet.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet() {
	Player player;

	speed = 0.3;
	position = player.position;
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

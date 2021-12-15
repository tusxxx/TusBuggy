#include "Explosion.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>

Explosion::Explosion() {
    position = sf::Vector2f(100, -1000);
    texture.loadFromFile("explosion.png");
    sprite.setTexture(texture);
    sprite.setScale(3.6, 3.6);
}

sf::Sprite Explosion::getSprite() {
    return sprite;
}

void Explosion::update() {
    sprite.setPosition(position);
}
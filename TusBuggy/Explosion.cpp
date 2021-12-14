#include "Explosion.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>

Explosion::Explosion() {
    texture.loadFromFile("explosion.png");
    sprite.setTexture(texture);
}

sf::Sprite Explosion::getSprite() {
    return sprite;
}

void Explosion::explosionUpdate() {
    sprite.setPosition(position);
    sprite.setScale(3.6, 3.6);
}

#include "Asteroid.h"

Asteroid::Asteroid() {
    position = sf::Vector2f(250,250);
    speed = 1.75f;
    goRight = false;
    texture.loadFromFile("asteroid.png");
    sprite.setTexture(texture);
    sprite.setOrigin(32, 32);
}

sf::Sprite Asteroid::getSprite() {
    return sprite;

}

void Asteroid::move() {
    if (position.x < 0) {
        goRight = true;
    } else if (position.x > 800-texture.getSize().x) {
        goRight = false;
    }
    if (goRight == true) {
        position.x += speed;
    } else {
        position.x -= speed;
    }
}

void Asteroid::explode() {
}

void Asteroid::update() {
    move();
    sprite.setPosition(position);
}

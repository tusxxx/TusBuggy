#include "Asteroid.h"

Asteroid::Asteroid() {
    position = sf::Vector2f(250,250);
    speed = 1.75f;
    goRight = false;
    asteroidTexture.loadFromFile("asteroid.png");
    asteridSprite.setTexture(asteroidTexture);
    asteridSprite.setOrigin(32, 32);
}

sf::Sprite Asteroid::getSprite() {
    return asteridSprite;

}

void Asteroid::move() {
    if (position.x < 0) {
        goRight = true;
    } else if (position.x > 800-asteroidTexture.getSize().x) {
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

void Asteroid::asteroidUpdate() {
    move();
    asteridSprite.setPosition(position);
}

#include "Asteroid.h"

Asteroid::Asteroid() {
    position = sf::Vector2f(300,300);
    speed = 0.2;
    goRight = false;
    asteroidTexture.loadFromFile("asteroid.png");
    asteridSprite.setTexture(asteroidTexture);
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

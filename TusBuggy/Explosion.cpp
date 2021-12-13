#include "Explosion.h"

Explosion::Explosion() {
    explosionShape = sf::CircleShape(10);
    explosionShape.setFillColor(sf::Color::Red);
}

sf::CircleShape Explosion::getExplosionShape() {
    return explosionShape;
}

void Explosion::explosionUpdate() {
    explosionShape.setScale(2, 2);
}

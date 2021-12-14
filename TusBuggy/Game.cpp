#include "Game.h"
#include <iostream>

Game::Game() {
    bulletOffset = sf::Vector2f(38, 0);
    explosionOffset = sf::Vector2f(96, 128);
        
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.scale(1.1f, 1.1f);
	sf::Vector2f resolution(800, 600);
	window.create(sf::VideoMode(resolution.x, resolution.y), "TusBuggy");
    window.setFramerateLimit(60);
}

void Game::start() {
    enemySetup();

    while (window.isOpen()) {
        input();
        colliderDetection();
        update();
        draw();
    }
}

void Game::input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }

    //------------------------- .bullet code
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bullet.isMove = true;
    }

    if (bullet.isMove == true) {
        bullet.fly();
        if (bullet.position.y < -100) {
            bullet.isMove = false;
        }
    }
    if (bullet.isMove == false) {
        bullet.position = player.position + bulletOffset;
    }
    //---------------------------

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.moveRight();
    }
}


void Game::update() {
    player.playerUpdate();
    bullet.bulletUpdate();
    enemyStackUpdate();
    asteroid.asteroidUpdate();
    explosion.explosionUpdate();
}

void Game::draw() {
    window.draw(backgroundSprite);
    window.draw(bullet.getSprite());
    window.draw(player.getSprite());
    for (int iterator = 0; iterator < 7; ++iterator) {
        window.draw(enemyStack[iterator].getSprite());
    }
    window.draw(asteroid.getSprite());
    window.draw(explosion.getSprite());

    window.display();
}

void Game::enemyStackUpdate() {
    for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
        if (enemyStack[enemyNumber].position.x > 730) {
            for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
                enemyStack[enemyNumber].goRight = false;
            }
        }
        if (enemyStack[enemyNumber].position.x < 0) {
            for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
                enemyStack[enemyNumber].goRight = true;
            }
        }
        enemyStack[enemyNumber].enemyUpdate();
    }
}

void Game::enemySetup() {
    float distance = 0;
    for (int iterator = 0; iterator < 7; ++iterator) {
        distance += 80;
        enemyStack[iterator].position.x += distance;
    }
}

void Game::colliderDetection() {
    if (bullet.getSprite().getGlobalBounds().intersects(asteroid.getSprite().getGlobalBounds())) {
        printf("a");
        explosion.position = asteroid.position - explosionOffset;
        bullet.isMove = false;
    }

    for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
        if (enemyStack[enemyNumber].getSprite().getGlobalBounds().intersects(bullet.getSprite().getGlobalBounds())) {
            printf("hit!");
            explosion.position = enemyStack[enemyNumber].position - explosionOffset;
            //enemyStack[enemyNumber].explode();
            bullet.isMove = false;
        }
    }
}
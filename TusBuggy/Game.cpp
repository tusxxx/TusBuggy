#include "Game.h"
#include <iostream>

Game::Game() {
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.scale(1.1f, 1.1f);
	sf::Vector2f resolution(800, 600);
	window.create(sf::VideoMode(resolution.x, resolution.y), "TusBuggy");
}

void Game::start() {
    enemySetup();

    while (window.isOpen())
    {
        input();
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
        bullet.position = player.position + sf::Vector2f(38, 0);
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
}

void Game::draw() {
    window.draw(backgroundSprite);
    window.draw(bullet.getSprite());
    window.draw(player.getSprite());
    for (int iterator = 0; iterator < 7; ++iterator) {
        window.draw(enemyStack[iterator].getSprite());
    }
    window.draw(asteroid.getSprite());
    window.display();
}

void Game::enemyStackUpdate()
{
    for (int iterator = 0; iterator < 7; ++iterator) {
        if (enemyStack[iterator].position.x > 730) {
            for (int iterator = 0; iterator < 7; ++iterator) {
                enemyStack[iterator].goRight = false;
            }
        }
        if (enemyStack[iterator].position.x < 0) {
            for (int iterator = 0; iterator < 7; ++iterator) {
                enemyStack[iterator].goRight = true;
            }
        }
        enemyStack[iterator].enemyUpdate();
    }
}

void Game::enemySetup()
{
    float distance = 0;
    for (int iterator = 0; iterator < 7; ++iterator) {
        distance += 80;
        enemyStack[iterator].position.x += distance;
    }
}

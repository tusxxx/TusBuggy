#include "Game.h"
#include <iostream>

Game::Game() {
	sf::Vector2f resolution(800, 600);
	window.create(sf::VideoMode(resolution.x, resolution.y), "TusBuggy");
}

void Game::start() {
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

    // .bullet code
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bullet.isMove = true;
    }

    if (bullet.isMove == true) {
        bullet.fly();
        if (bullet.position.y < 0) {
            bullet.position = player.position;
            bullet.isMove = false;
        }
    }
    if (bullet.isMove == false) {
        bullet.position = player.position;
    }
    //

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
}

void Game::draw() {
    window.clear(sf::Color::Black);
    
    window.draw(bullet.getShape());
    window.draw(player.getSprite());
    
    window.display();
}

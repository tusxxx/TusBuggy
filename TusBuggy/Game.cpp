#include "Game.h"

Game::Game() {
    bulletOffset = sf::Vector2f(38, -32);
    explosionOffset = sf::Vector2f(96, 128);
        
    texture.loadFromFile("background.jpg");
    sprite.setTexture(texture);
    sprite.scale(1.1f, 1.1f);
	sf::Vector2f resolution(800, 600);

	window.create(sf::VideoMode(resolution.x, resolution.y), "TusBuggy");
    window.setFramerateLimit(60);
}

void Game::start() {
    enemySetup();

    sf::Music music;
    music.openFromFile("invadeaac.wav"); // .ne kruto
    music.play();
    music.setLoop(true);

    while (window.isOpen()) {
        if (isLosed == false && isWinned == false) {
            input();
            update();
            draw();
            colliderDetection();
        } else if (isLosed == true) {
            lose();
        }
        if (isWinned == true) {
            win();
        }
    }
}

void Game::lose() { // .slishkom gromozdkiy
    window.clear(sf::Color::Black);
    sf::Text loseText;
    sf::Font calibriFont;
    calibriFont.loadFromFile("calibri.ttf");
    loseText.setFont(calibriFont);
    loseText.setString("You lose! Press space to defeat last enemies.");
    loseText.setCharacterSize(36);
    loseText.setFillColor(sf::Color::Red);
    loseText.setPosition(loseText.getPosition().x, loseText.getPosition().y + 350);
    window.draw(loseText);
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isLosed = false;
    }
}

void Game::win() {
    window.clear(sf::Color::Black);
    sf::Text winText;
    sf::Font calibriFont;
    calibriFont.loadFromFile("calibri.ttf");
    winText.setFont(calibriFont);
    winText.setString("You win. Rodina mat` tebya ne zabudet");
    winText.setCharacterSize(36);
    winText.setFillColor(sf::Color::Green);
    winText.setPosition(winText.getPosition().x, winText.getPosition().y + 350);
    window.draw(winText);
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
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
    //--------------------------- .ploho, chto on tut

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.moveRight();
    }
}


void Game::update() {
    player.update();
    bullet.update();
    enemyStackUpdate();
    asteroid.update();
    //explosion.update();  
}

void Game::draw() {
    window.draw(sprite);
    window.draw(bullet.getSprite());
    window.draw(player.getSprite());
    for (int iterator = 0; iterator < 7; ++iterator) {
        window.draw(enemyStack[iterator].getSprite());
    }
    window.draw(asteroid.getSprite());
    //window.draw(explosion.getSprite());

    window.display();
}

void Game::enemyStackUpdate() {
    for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
        if (enemyStack[enemyNumber].position.x > 730) {
            //for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
                enemyStack[enemyNumber].goRight = false;
            //}
        }
        if (enemyStack[enemyNumber].position.x < 0) {
            //for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
                enemyStack[enemyNumber].goRight = true;
            //}
        }
        enemyStack[enemyNumber].update();
    }
    
    if (enemyStack[0].position.y > 1000 && enemyStack[1].position.y > 1000 && // .gryano
        enemyStack[2].position.y > 1000 && enemyStack[3].position.y > 1000 &&
        enemyStack[4].position.y > 1000 && enemyStack[5].position.y > 1000 &&
        enemyStack[6].position.y > 1000) {
        isWinned = true;
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
        bullet.isMove = false;
    }

    for (int enemyNumber = 0; enemyNumber < 7; ++enemyNumber) {
        if (enemyStack[enemyNumber].getSprite().getGlobalBounds().intersects(bullet.getSprite().getGlobalBounds())) {
            explosion.position = enemyStack[enemyNumber].position - explosionOffset;
            enemyStack[enemyNumber].isExploded = true;
            bullet.isMove = false;
        }

        if (enemyStack[enemyNumber].getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
            isLosed = true;
            enemyStack[enemyNumber].position.y = 10000;
        }
    }
}
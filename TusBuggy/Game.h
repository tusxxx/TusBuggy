#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Enemy.h"
#include "Asteroid.h"

class Game {
private:	
	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	Bullet bullet;
	Player player;
	Explosion explosion;
	Enemy enemyStack[7];
	Asteroid asteroid;

	void input();
	void update();
	void draw();
	void enemyStackUpdate();
	void enemySetup();

public:
	Game();
	void start();
};


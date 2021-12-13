#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Enemy.h"

class Game {
private:	
	sf::RenderWindow window;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	Bullet bullet;
	Player player;
	Explosion explosion;
	Enemy enemyStack[7];

	void input();
	void update();
	void draw();
	void enemyStackUpdate();
	void enemySetup();

public:
	Game();
	void start();
};


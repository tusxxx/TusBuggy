#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Explosion.h"

class Game {
private:	
	sf::RenderWindow window;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	Bullet bullet;
	Player player;
	Explosion explosion;

	void input();
	void update();
	void draw();

public:
	Game();
	void start();
};


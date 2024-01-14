#pragma once
#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "SFML/Graphics.hpp"

class Game
{
private:

	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	Deck deck;
	Card* carta;

public:
	Game();
	~Game();
	void run();
	

private:
	void init();
	void update();
	void draw();
};

#endif



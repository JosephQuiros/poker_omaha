#pragma once
#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "menu.h"
#include "SFML/Graphics.hpp"

class Game
{
private:
	Menu mainMenu;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	Deck deck;
	Player* playersArray;
	int actualCardDeck;



public:
	Game();
	~Game();
	void run();
	void playPoker(int numPlayers);
	

private:
	void init(int numPlayers);
	void update();
	void draw();
	void dealCardsToPlayers(int numPlayers);
	void createWindow();
};

#endif



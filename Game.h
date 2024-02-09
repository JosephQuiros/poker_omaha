#pragma once
#ifndef GAME_H
#define GAME_H


#include "Menu.h"
#include "Player.h"
#include "Dealer.h"
#include "RectangleButton.h"

class Game
{
private:
	Menu mainMenu;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	Dealer* dealer;
	Player* playersArray;
	static const int TOTAL_BUTTONS = 3;
	Button* buttonArray[TOTAL_BUTTONS];



public:
	Game();
	~Game();
	void run();
	void playPoker(int numPlayers);
	

private:
	void startGame(int numPlayers);
	void update();
	void draw(int numPlayers);
	void dealCardsToPlayers(int numPlayers);
	void createWindow();
	void setPlayerAndDealerPosition(int numPlayers);
	void drawPlayers(int numPlayers);
	void drawButtons();
	void createbutton();
	void init();
};

#endif



#pragma once
#ifndef POKER_H
#define POKER_H

#include "List.h"
#include "Dealer.h"
#include "RectangleButton.h"

class Poker
{
private:
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	Dealer* dealer;
	List* playerList;
	static const int TOTAL_BUTTONS = 3;
	Button* buttonArray[TOTAL_BUTTONS];
	int numPlayers;
	int playersInThisRound;
	int turnPlayer;
	Player* currentPlayer;
	


public:
	Poker(int numPlayer);
	~Poker();
	void play();
	
private:
	void loop();
	void update();
	void draw();
	void dealCardsToPlayers();
	void preGame();
	void createWindow();
	void setPlayerAndDealerPosition();
	void drawButtons();
	void createbutton();
	int findTheButtonPressed(sf::Vector2f& mousePos);
	void whatButtonWasPressed(sf::Vector2f mousePos);
	void postGame();
};
#endif



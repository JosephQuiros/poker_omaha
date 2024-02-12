#pragma once
#ifndef POKER_H
#define POKER_H

#include "List.h"
#include "Dealer.h"
#include "RectangleButton.h"
#include "BetSystem.h"

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
	BetSystem* betWindow;
	int numPlayers;
	int numPlayersInThisRound;
	int turnPlayer;
	int numRounds;
	Player* currentPlayer;
	


public:
	Poker(int numPlayer);
	~Poker();
	void play();
	
private:
	void loop(int iterations);
	void update();
	void draw();
	void dealCardsToPlayers();
	void preGame();
	void prefloop();
	void createWindow();
	void setPlayerAndDealerPosition();
	void drawButtons();
	void createbutton();
	int findTheButtonPressed(sf::Vector2f& mousePos);
	void whatButtonWasPressed(sf::Vector2f& mousePos);
	void postGame();
	void getBet(int player, int amount);
};
#endif



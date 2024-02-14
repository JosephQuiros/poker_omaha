#pragma once
#ifndef POKER_H
#define POKER_H

#include "List.h"
#include "Dealer.h"
#include "RectangleButton.h"
#include <fstream>

class Poker
{
private:
	sf::Text textClock;
	sf::Font font;
	sf::Clock clock;
	sf::Time startTime;
	int countdownSeconds;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	Dealer* dealer;
	List* playerList;
	static const int TOTAL_BUTTONS = 4;
	Button* buttonArray[TOTAL_BUTTONS];
	int numPlayers;
	int numPlayersInThisRound;
	int turnPlayer;
	int totalRounds;
	int numRound;
	int lastBet;
	Player* currentPlayer;
	sf::Text text;
	std::ofstream saveFile;

public:
	Poker(int numPlayer);
	~Poker();
	void play();	
	
private:
	void startClock();
	void prefloopLoop();
	void gameLoop();
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
	void nextTurn();
	void call();
	void raise();
	void restartTextOfLastBet();
	void makeEndLine(int iterations);
	Player* findPokerButtonInPlayer(PokerButton* button);
	void saveNumPlayersInthisGame();
	void savePlayersWithPokerButton();
	void saveCardsOfPlayer(Player* player);
	void saveCommunityCards(Card** communityCards);
	void fileWasCloseInGame();
};
#endif



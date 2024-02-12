#pragma once
#ifndef BETSYSTEM_H
#define BETSYSTEM_H

#include "RectangleButton.h"
#include "TriangleButton.h"
#include "Dealer.h"
#include"List.h"

class BetSystem
{
private:
	sf::RectangleShape background;
	static const int MAX_BUTTONS= 2;
	Button* buttonArray[MAX_BUTTONS];
	sf::Font font;
	sf::Text text;
	bool visible;
	float posX;
	float posY;
	float width;
	float height;
	int lastBet;
	List* playerList;
	Dealer* dealer;

public:
	BetSystem(List* list, Dealer* dealer);
	~BetSystem();
	void drawOnWindow(sf::RenderWindow& window);
	bool isVisible();
	void setVisible(bool visible);
	void setPosition(float posX, float posY);
	void whatButtonWasPressed(sf::Vector2f& mousePos, int& turnPlayer, int& numPlayers, int& numRound, Player*& currentPlayer);
	void restart();

private:
	int findTheButtonPressed(sf::Vector2f& mousePos);
	void createButtons();
	void nextTurn(int& turnPlayer, int& numPlayers, int& numRound, Player*& currentPlayer);
	void call(Player*& currentPlayer);
	void raise(Player*& currentPlayer);
	
};

#endif
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "PokerButton.h"


class Player
{
private:
	static const int MAX_CARDS = 4;
	Card* ownDeck[MAX_CARDS];
	static const int MAX_BUTTONS = 2;
	PokerButton* pokerButtons[2];
	PokerButton* coins;
	sf::Text id;
	sf::Font font;
	int numCardsOnDeck;
	bool cardIsVisible;
	bool isInGame;
	float posX;
	float posY;

public:
	Player(int idPlayer);
	~Player();
	void takeCard(Card* card);
	void returnCardToDeck();
	void drawOnWindow(sf::RenderWindow &window);
	void takePokerButton(PokerButton* pokerButton);
	void setPosition(float posX, float posY);
	bool CardIsVisible();
	void setCardIsVisible(bool isVisible);
	void setIsInGame(bool isInGame);
private:
	void setIdPlayer(int idPlayer);
};

#endif
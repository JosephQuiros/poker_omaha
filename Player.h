#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"


class Player
{
private:
	static const int MAX_CARDS = 4;
	Card* ownDeck[MAX_CARDS];
	int numCardsOnDeck;
	bool cardIsVisible;
	bool isInGame;
	float posX;
	float posY;

public:
	Player();
	~Player();
	void takeCard(Card* card);
	void returnCardToDeck();
	void drawCards(sf::RenderWindow &window);
	void setPosition(float posX, float posY);
	bool getCardIsVisible();
	void setCardIsVisible(bool isVisible);
	void setIsInGame(bool isInGame);
private:

};

#endif
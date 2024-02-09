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
	float posX;
	float posY;

public:
	Player();
	~Player();
	void takeCard(Card* card);
	void drawCards(sf::RenderWindow &window);
	void setPosition(float posX, float posY);

private:

};

#endif
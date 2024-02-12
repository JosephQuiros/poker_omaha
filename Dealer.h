#pragma once
#ifndef DEALER_H
#define DEALER_H
#include "Card.h"
#include "Deck.h"
#include "List.h"
#include "PokerButton.h"

class Dealer
{
private:
	static const int MAX_CARDS = 5;
	Deck* deck;
	Card* communityDeck[MAX_CARDS];
	PokerButton** pokerButtons;
	PokerButton* pot;
	int positionInDeck;
	int numCommunityCards;
	float posX;
	float posY;

public:
	Dealer();
	~Dealer();
	void dealCard(Player* player);
	void takeCard(int iterations);
	void setPosition(float posX, float posY);
	void drawCards(sf::RenderWindow& window);
	void returnCommunityCardsToDeck();
	void shuffleDeck();
	PokerButton** getPokerButtons();
	PokerButton* getPokerButton(int pos);
	PokerButton* getPot();
private:
	void createPokerButtons();
};

#endif



#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <stdlib.h>

class Deck
{
private:
	const int MAX = 52;
	Card* deck[52];
	

public:
	Deck();
	~Deck();
	void printCard(); //debug
	void shuffleDeck();

private:
	
	int getRandomNum(int position);
	void swapCard(Card*& card1, Card*& card2);
};
#endif 


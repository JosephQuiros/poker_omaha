#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <stdlib.h>

class Deck
{
private:
	static const int MAX = 52;
	Card* deck[MAX];
	

public:
	Deck();
	~Deck();
	void printCard(); //debug
	void shuffle();
	Card* getCard(int pos);


private:
	
	int getRandomNum(int position);
	void swapCard(Card* &card1, Card* &card2);
	void createCards();
};
#endif 


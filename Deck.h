#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
	const int MAX = 52;
	Card deck[52];

public:
	Deck();
	~Deck();
	

};
#endif 


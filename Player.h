#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"


class Player
{
private:
	int MAX_CARDS = 4;
	Card* ownDeck[];

public:
	Player();
	~Player();

private:

};

#endif
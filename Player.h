#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"


class Player
{
private:
	static const int MAX_CARDS = 4;
	Card* ownDeck[MAX_CARDS];
	float posX;
	float posY;

public:
	Player();
	~Player();

private:

};

#endif
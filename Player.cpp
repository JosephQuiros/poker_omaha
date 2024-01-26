#include "Player.h"

Player::Player()
{
	int i;

	for (i = 0; i < MAX_CARDS; i++) {
		ownDeck[i] = nullptr;
	}
}

Player::~Player()
{

}

#include "Player.h"

Player::Player()
{
	int i;
	numCardsOnDeck = 0;
	posX = 0.f;
	posY = 0.f;
	cardIsVisible = false;
	isInGame = true;
	for (i = 0; i < MAX_CARDS; i++) {
		ownDeck[i] = nullptr;
	}
}

Player::~Player()
{
}

void Player::takeCard(Card* card)
{
	if (numCardsOnDeck < MAX_CARDS) {
		ownDeck[numCardsOnDeck] = card;
		card->setPostions(posX + numCardsOnDeck * 72, posY);
		numCardsOnDeck++;
	}

}

void Player::returnCardToDeck()
{
	int i;

	for (i = 0; i < numCardsOnDeck; i++) {
		ownDeck[i] = nullptr;
	}
	numCardsOnDeck = 0;
}

void Player::drawCards(sf::RenderWindow& window)
{
	if (isInGame) {
		int i;
		if (cardIsVisible) {
			for (i = 0; i < numCardsOnDeck; i++) {
				window.draw(ownDeck[i]->getFrontSprite());
			}
			return;
		}

		for (i = 0; i < numCardsOnDeck; i++) {
			window.draw(ownDeck[i]->getBackSprite());
		}
	}
	return;
}

void Player::setPosition(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;

	if (numCardsOnDeck >= 1) {
		int i;
		for (i = 0; i < numCardsOnDeck; i++) {
			ownDeck[i]->setPostions(posX + i * 72, posY);
		}
	}
}

bool Player::getCardIsVisible()
{
	return cardIsVisible;
}

void Player::setCardIsVisible(bool visible)
{
	this->cardIsVisible = visible;
}

void Player::setIsInGame(bool isInGame)
{
	this->isInGame = isInGame;
}

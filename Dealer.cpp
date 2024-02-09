#include "Dealer.h"

Dealer::Dealer()
{
	this->posX = 0;
	this->posY = 0;
	this->positionInDeck = 0;
	this->numDealerCards = 0;
	deck = new Deck();
	deck->shuffle();

	int i;
	for (i = 0; i < MAX_CARDS; i++) {
		dealerDeck[i] = nullptr;
	}
}

Dealer::~Dealer() {
	delete deck;
}

void Dealer::dealCard(Player& player)
{
	player.takeCard(deck->getCard(positionInDeck));
	positionInDeck++;
}

void Dealer::takeCard(int iterations)
{
	int i;
	for (i = 0; i < iterations; i++) {
		if (numDealerCards < MAX_CARDS) {
			Card* card = deck->getCard(positionInDeck);
			positionInDeck++;

			dealerDeck[numDealerCards] = card;
			card->setPostions(posX + numDealerCards * 72, posY);
			numDealerCards++;
		}
	}
}

void Dealer::setPosition(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Dealer::drawCards(sf::RenderWindow& window)
{
	int i;

	for (i = 0; i < numDealerCards; i++) {
		window.draw(dealerDeck[i]->getSprite());
	}
}

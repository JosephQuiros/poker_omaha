#include "Dealer.h"

Dealer::Dealer()
{
	this->posX = 0;
	this->posY = 0;
	this->positionInDeck = 0;
	this->numCommunityCards = 0;
	deck = new Deck();

	int i;
	for (i = 0; i < MAX_CARDS; i++) {
		communityDeck[i] = nullptr;
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
		if (numCommunityCards < MAX_CARDS) {
			Card* card = deck->getCard(positionInDeck);
			positionInDeck++;

			communityDeck[numCommunityCards] = card;
			card->setPostions(posX + numCommunityCards * 72, posY);
			numCommunityCards++;
		}
	}
}

void Dealer::returnCommunityCardsToDeck()
{
	int i;
	for (i = 0; i < numCommunityCards; i++) {

	}
	numCommunityCards = 0;
}

void Dealer::shuffleDeck()
{
	positionInDeck = 0;
	deck->shuffle();
}

void Dealer::setPosition(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Dealer::drawCards(sf::RenderWindow& window)
{
	int i;

	for (i = 0; i < numCommunityCards; i++) {
		window.draw(communityDeck[i]->getFrontSprite());
	}
}

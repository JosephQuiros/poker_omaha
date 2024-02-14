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
	createPokerButtons();
}

Dealer::~Dealer() {
	int i;

	for (i = 0; i < 3; i++) {
		delete pokerButtons[i];
	}

	delete[] pokerButtons;
	delete deck;
	delete pot;
}

void Dealer::dealCard(Player* player)
{
	player->takeCard(deck->getCard(positionInDeck));
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

void Dealer::createPokerButtons()
{
	pokerButtons = new PokerButton*[3];
	pokerButtons[0] = new PokerButton(sf::Color::White, "Fonts/times.ttf", "D");
	pokerButtons[1] = new PokerButton(sf::Color::Yellow, "Fonts/times.ttf", "LB");
	pokerButtons[2] = new PokerButton(sf::Color::Red, "Fonts/times.ttf", "BB");

	pot = new PokerButton(sf::Color::Blue, "Fonts/times.ttf", 0);

}

void Dealer::returnCommunityCardsToDeck()
{
	int i;
	for (i = 0; i < numCommunityCards; i++) {
		communityDeck[i] = nullptr;
	}
	numCommunityCards = 0;
}

void Dealer::shuffleDeck()
{
	positionInDeck = 0;
	deck->shuffle();
}

PokerButton** Dealer::getPokerButtons()
{
	return pokerButtons;
}

PokerButton* Dealer::getPokerButton(int pos)
{
	return pokerButtons[pos];
}

PokerButton* Dealer::getPot()
{
	return pot;
}

Card** Dealer::getCommunityDeck()
{
	return communityDeck;
}

bool Dealer::haveCards()
{
	if (numCommunityCards > 1) {
		return true;
	}
	return false;
}

int Dealer::getnumOfCommunityDeck()
{
	return numCommunityCards;
}

void Dealer::setPosition(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;

	pot->setPosition(posX + (MAX_CARDS * 72), posY);
}

void Dealer::drawCards(sf::RenderWindow& window)
{
	int i;
	pot->draw(window);
	for (i = 0; i < numCommunityCards; i++) {
		window.draw(communityDeck[i]->getFrontSprite());
	}
}

#include "Deck.h"

Deck::Deck()
{
	
	std::string cardDir[] = { "1C", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "11C", "12C", "13C", "1D", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "11D", "12D", "13D", "1H", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "11H", "12H", "13H", "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "11S", "12S", "13S"};
	std::string path = "Cards/";
	std::string png = ".png";

	int pSuit, pIndex, aux = 0;
	
	for (pSuit = 0; pSuit < 4; pSuit++)
	{
		for (pIndex = 1; pIndex <= 13; pIndex++)
		{
			deck[aux] = new Card(pIndex, pSuit, path + cardDir[aux] + png);
			aux++;
		}
	}
}

Deck::~Deck()
{
	int i;
	for (i = 0; i < MAX; i++) {
		delete deck[i];
	}
}

void Deck::printCard()
{
	int i;

	shuffleDeck();

	for (i = 0; i < MAX; i++) {
		std::cout << deck[i]->getIndex() << "----" << deck[i]->getSuit() << "\n";
	}
}

void Deck::shuffleDeck()
{
	int i, randomNum;
	
	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		randomNum = getRandomNum(i);
		swapCard(deck[i], deck[randomNum]);
	}
}

Card* Deck::getCard(int pos)
{
	return deck[pos];
}

int Deck::getRandomNum(int position)
{

	return position + rand() % (MAX - position);
}

void Deck::swapCard(Card*& card1, Card*& card2)
{
	Card* aux;

	aux = card1;
	card1 = card2;
	card2 = aux;
}

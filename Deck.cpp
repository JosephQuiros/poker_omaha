#include "Deck.h"

Deck::Deck()
{
	std::string cardDir[] = {"2D","2C"};
	std::string path = "Cards/";
	std::string png = ".png";

	int i, j, aux = 0;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			deck[aux] = Card(j, i, path + cardDir[0] + png);
			aux++;
		}
	}
}

Deck::~Deck()
{
}

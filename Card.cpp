#include "Card.h"

Card::Card()
{
	this->index = NULL;
	this->suit = NULL;
	
}

Card::Card(int index, int suit, std::string dir)
{
	sf::Texture texture;

	this->index = index;
	this->suit = suit;

	shape.setSize(sf::Vector2f(62, 90));


	if (!texture.loadFromFile(dir)) {
		std::cout << "error ";
		exit(-1);
	}
	shape.setTexture(&texture);

}

Card::~Card()
{
}

int Card::getIndex()
{
	return index;
}

int Card::getSuit()
{
	return suit;
}

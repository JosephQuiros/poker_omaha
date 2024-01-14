#include "Card.h"

Card::Card()
{
	this->index = NULL;
	this->suit = NULL;
	
}

Card::Card(int index, int suit, std::string dir)
{

	this->index = index;
	this->suit = suit;


	if (!texture.loadFromFile(dir)) {
		std::cout << "error ";
		exit(-1);
	}
	shape.setTexture(texture);

}

Card::~Card()
{
}

sf::Sprite Card::getSprite()
{
	return shape;
}

int Card::getIndex()
{
	return index;
}

int Card::getSuit()
{
	return suit;
}

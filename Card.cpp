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


	if (!frontTexture.loadFromFile(dir) || !backTexture.loadFromFile("Cards/BC.png")) {
		std::cout << "error ";
		exit(-1);
	}

	frontSprite.setTexture(frontTexture);
	backSprite.setTexture(backTexture);
}

Card::~Card()
{
}

sf::Sprite Card::getFrontSprite()
{
	return frontSprite;
}

sf::Sprite Card::getBackSprite()
{
	return backSprite;
}

void Card::setPostions(float posX, float posY)
{
	frontSprite.setPosition(posX, posY);
	backSprite.setPosition(posX, posY);
}

int Card::getIndex()
{
	return index;
}

int Card::getSuit()
{
	return suit;
}

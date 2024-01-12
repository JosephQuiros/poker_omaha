#include "Card.h"

Card::Card()
{

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

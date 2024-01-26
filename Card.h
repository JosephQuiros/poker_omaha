#pragma once

#ifndef CARD_H
#define CARD_H

#include "SFML/Graphics.hpp"
#include <iostream>


class Card
{
private:
	int index;
	int suit;
	sf::Texture texture;
	sf::Sprite shape;



public:
	Card();
	Card(int index, int suit, std::string dir);
	~Card();
	sf::Sprite getSprite();
	int getIndex(); //debug
	int getSuit(); //debug


};
#endif 



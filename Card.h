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
	sf::Texture frontTexture;
	sf::Texture backTexture;
	sf::Sprite frontSprite;
	sf::Sprite backSprite;



public:
	Card();
	Card(int index, int suit, std::string dir);
	~Card();
	sf::Sprite getFrontSprite();
	sf::Sprite getBackSprite();
	void setPostions(float posX, float posY);
	int getIndex(); //debug
	int getSuit(); //debug


};
#endif 



#pragma once
#ifndef POKERBUTTON_H
#define POKERBUTTON_H
#include "SFML/Graphics.hpp"

class PokerButton
{
private:
	sf::CircleShape shape;
	sf::Font font;
	sf::Text text;
	float posX;
	float posY;
	float widthOfSprite;
	float heightOfSprite;
	int coin;

public:
	PokerButton(sf::Color color, std::string fontDir, std::string text);
	PokerButton(sf::Color color, std::string fontDir, int totalCoins);
	~PokerButton();
	void setPosition(float posX, float posY);
	void draw(sf::RenderWindow& window);

private:
	void setCenteredText();

};
#endif


#pragma once
#ifndef MENU_H
#define MENU_H
#include "RectangleButton.h"
#include "TriangleButton.h"
#include "Poker.h"

class Menu
{
private:

	Poker* poker;
	sf::RenderWindow window;
	sf::Font font;
	sf::Text text;
	static const int TOTAL_BUTTONS = 7;
	Button* buttonArray[TOTAL_BUTTONS];
	int optionMenu;
	int numPlayers;

public:
	Menu();
	~Menu();
	void run();
	
private:
	void init();
	void draw();
	void createButtons();
	int findTheButtonPressed(sf::Vector2f& mousePos);
	void drawScene();
	void whatButtonWasPressed(sf::Vector2f mousePos);
	void backToMenu();
	void selectPlayers();
};


#endif 

#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream> //debug
#include "SFML/Graphics.hpp"
#include "RectangleButton.h"

class Menu
{
private:
	sf::RenderWindow window;
	RectangleButton rectanglebutton[3];
	int optionMenu;
	int numPlayers;


public:
	Menu();
	~Menu();
	void init();
	void run();
	void update();
	void draw();
};


#endif 

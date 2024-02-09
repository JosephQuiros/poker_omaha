#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream> //debug
#include "SFML/Graphics.hpp"
#include "RectangleButton.h"
#include "TriangleButton.h"

class Menu
{
private:

	
	sf::RenderWindow window;
	static const int TOTAL_BUTTONS = 7;
	Button* buttonArray[TOTAL_BUTTONS];
	int optionMenu;
	int numPlayers;

public:
	Menu();
	~Menu();
	int selectNumPlayer();
	sf::Window* getWindow();
	
private:
	void init();
	void update();
	void draw();
	void createButtons();
	int findTheButtonPresed(sf::Vector2f& mousePos);
	void drawScene();
	int findButton(sf::Vector2f mousePos);
};


#endif 

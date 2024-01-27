#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include <iostream> //debug
#include "SFML/Graphics.hpp"
class Button
{
protected:
	float posX;
	float posY;

public:
	Button();
	Button(float x,float y);
	~Button();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool isPressed(sf::Vector2f& mousePos) = 0;
};

#endif 


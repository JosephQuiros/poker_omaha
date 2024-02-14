#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include "SFML/Graphics.hpp"
class Button
{
protected:
	float posX;
	float posY;
	bool isVisible;

public:
	Button();
	Button(float x,float y);
	~Button();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool isPressed(sf::Vector2f& mousePos) = 0;
	virtual void setPostion(float posX, float posY) = 0;
	virtual void setVisibility(bool visible) = 0;
	virtual void rotate(float angle) = 0;
};

#endif 


#pragma once
#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H
#include "Button.h"

class RectangleButton : public Button
{
private:
	sf::RectangleShape shape;
	sf::Text text;


public:
	RectangleButton();
	RectangleButton(float posX, float posY,float width,float height, std::string font, std::string text);

	~RectangleButton();
	void draw(sf::RenderWindow &window);
};


#endif // !RECTANGLEBUTTON_H

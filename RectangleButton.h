#pragma once
#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H
#include "Button.h"

class RectangleButton : public Button
{
private:
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	float  height;
	float width;

public:
	RectangleButton(float width, float height, std::string tittleButton, std::string fontDir);
	~RectangleButton();
	void draw(sf::RenderWindow &window);
	void setPostion(float posX, float posY);
	bool isPressed(sf::Vector2f& mousePos);
	void setVisibility(bool visible);
	void rotate(float angle);

private:
	void setCenteredText();
	
};


#endif
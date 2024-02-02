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
	RectangleButton();
	~RectangleButton();
	void draw(sf::RenderWindow &window);
	void create(float width, float height, std::string tittleButton,std::string fontDir);
	void setPostion(float posX, float posY);
	bool isPressed(sf::Vector2f& mousePos);
	void setVisibility(bool visible);
	
private:
	void setCenteredText();
	void create(float size);
	void rotate(float angle);
};


#endif
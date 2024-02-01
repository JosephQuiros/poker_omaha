#pragma once
#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H
#include "Button.h"

class RectangleButton : public Button
{
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Font font;
	sf::Text text;

public:
	RectangleButton();
	~RectangleButton();
	void draw(sf::RenderWindow &window);
	void create(float width, float height, std::string dir);
	void setPostion(float posX, float posY);
	bool isPressed(sf::Vector2f& mousePos);
};


#endif
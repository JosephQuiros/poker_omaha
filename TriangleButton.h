#pragma once
#ifndef TRIANGLE_BUTTON
#define TRIANGLE_BUTTON
#include "Button.h"

class TriangleButton: public Button
{
private:
	sf::CircleShape tringleButton;
	float size;

public:
	TriangleButton(float size);
	~TriangleButton();
	
	 void draw(sf::RenderWindow& window) ;
	 bool isPressed(sf::Vector2f& mousePos) ;
	 void setPostion(float posX, float posY);
	 void setVisibility(bool visible) ;
	 void rotate(float angle);

private:

};

#endif // !TRIANGLE_BUTTON

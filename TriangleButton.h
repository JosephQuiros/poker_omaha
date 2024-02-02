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
	TriangleButton();
	~TriangleButton();
	
	 void draw(sf::RenderWindow& window) ;
	 bool isPressed(sf::Vector2f& mousePos) ;
	 void create(float size);
	 void setPostion(float posX, float posY);
	 void setVisibility(bool visible) ;
	 void rotate(float angle);

private:
	void create(float width, float height, std::string tittleButton, std::string fontDir);

};

#endif // !TRIANGLE_BUTTON

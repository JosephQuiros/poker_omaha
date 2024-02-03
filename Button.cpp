#include "Button.h"

Button::Button()
{
	posX = 0;
	posY = 0;
	isVisible = false;
}

Button::Button(float x, float y)
{
	this->posX = x;
	this->posY = y;
	isVisible = false;
}

Button::~Button()
{
}


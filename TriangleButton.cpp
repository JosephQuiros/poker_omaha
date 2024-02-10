#include "TriangleButton.h"

TriangleButton::TriangleButton(float size)
{
	posX = 0;
	posY = 0;
	this->size = size;

	isVisible = false;

	triangleButton.setRadius(size);
	triangleButton.setPointCount(3);

	triangleButton.setPosition(sf::Vector2f(posX, posY));
}

TriangleButton::~TriangleButton()
{
}

void TriangleButton::draw(sf::RenderWindow& window)
{
	if(isVisible)
	window.draw(triangleButton);
}

bool TriangleButton::isPressed(sf::Vector2f& mousePos)
{
	if (isVisible && triangleButton.getGlobalBounds().contains(mousePos))
		return true;
	
	return false;
}

void TriangleButton::setPostion(float posX, float posY)
{
	triangleButton.setPosition(sf::Vector2f(posX, posY));
}

void TriangleButton::setVisibility(bool visible)
{
	isVisible = visible;
}

void TriangleButton::rotate(float angle)
{
	triangleButton.rotate(angle);
}

#include "TriangleButton.h"

TriangleButton::TriangleButton()
{
}

TriangleButton::~TriangleButton()
{
}

void TriangleButton::draw(sf::RenderWindow& window)
{
	if(isVisible)
	window.draw(tringleButton);
}

bool TriangleButton::isPressed(sf::Vector2f& mousePos)
{
	if (isVisible && tringleButton.getGlobalBounds().contains(mousePos))
		return true;

	return false;
}

void TriangleButton::create(float size)
{
	posX = 0;
	posY = 0;
	this->size = size;

	isVisible = false;

	tringleButton.setRadius(size);
	tringleButton.setPointCount(3);

	tringleButton.setPosition(sf::Vector2f(posX, posY));

}

void TriangleButton::setPostion(float posX, float posY)
{
	tringleButton.setPosition(sf::Vector2f(posX, posY));
}

void TriangleButton::setVisibility(bool visible)
{
	isVisible = visible;
}

void TriangleButton::rotate(float angle)
{
	tringleButton.rotate(angle);
}

void TriangleButton::create(float width, float height, std::string tittleButton, std::string fontDir)
{
}

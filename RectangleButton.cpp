#include "RectangleButton.h"

RectangleButton::RectangleButton()
{
}


RectangleButton::~RectangleButton()
{
}

void RectangleButton::draw(sf::RenderWindow& window)
{
	if (isVisible) {

		window.draw(shape);
		window.draw(text);
	}

}

void RectangleButton::create(float width, float height,std::string tittleButton, std::string fontDir)
{
	posX = 0;
	posY = 0;
	this->width = width;
	this->height = height;

	isVisible = false;

	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(posX, posY));

	if (!font.loadFromFile(fontDir)) {
		std::cout << "error";
		exit(-3);
	}
	text.setFont(font);
	text.setString(tittleButton);
	text.setFillColor(sf::Color::Black);

	setCenteredText();	
}

void RectangleButton::setCenteredText()
{
	sf::FloatRect textBoud = text.getLocalBounds();
	text.setOrigin(textBoud.left + textBoud.width / 2.0f, textBoud.top + textBoud.height / 2.0f);
	text.setPosition(posX + width / 2.f, posY + height / 2.f);
}

void RectangleButton::setPostion(float posX, float posY)
{
	shape.setPosition(posX, posY);
	text.setPosition(posX + width /2.f , posY + height / 2.f);
}


bool RectangleButton::isPressed(sf::Vector2f& mousePos)
{
	if (isVisible && shape.getGlobalBounds().contains(mousePos))
		return true;

	return false;
}

void RectangleButton::setVisibility(bool visible)
{
	isVisible = visible;

}

void RectangleButton::create(float size)
{
}

void RectangleButton::rotate(float angle)
{
}


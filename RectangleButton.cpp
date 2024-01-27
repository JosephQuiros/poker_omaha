#include "RectangleButton.h"

RectangleButton::RectangleButton()
{
}
RectangleButton::RectangleButton(float posX, float posY,float width, float height, std::string font, std::string text) : Button(posX,posY)
{
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(posX, posY));
	sf::Font fonts;

	if (!fonts.loadFromFile(font)) {
		std::cout << "error ";
		exit(-1);
	}
	this-> text.setFont(fonts);
	this->text.setString(text);
}

RectangleButton::~RectangleButton()
{
}

void RectangleButton::draw(sf::RenderWindow& window)
{

}

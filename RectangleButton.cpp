#include "RectangleButton.h"

RectangleButton::RectangleButton()
{
}


RectangleButton::~RectangleButton()
{
}

void RectangleButton::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}

void RectangleButton::create(float width, float height, std::string dir)
{
	posX = 0;
	posY = 0;
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(posX, posY));

	if (!texture.loadFromFile(dir)) {
		std::cout << "error";
		exit(-2);
	}
	shape.setTexture(&texture);
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "errol";
		exit(-3);
	}
	text.setFont(font);
	text.setString("HOlaMundio");
	text.setFillColor(sf::Color::Black);
}

void RectangleButton::setPostion(float posX, float posY)
{
	shape.setPosition(posX, posY);
}

bool RectangleButton::isPressed(sf::Vector2f& mousePos)
{
	return shape.getGlobalBounds().contains(mousePos);
}

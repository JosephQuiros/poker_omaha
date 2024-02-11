#include "PokerButton.h"

PokerButton::PokerButton(sf::Color color, std::string fontDir, std::string text)
{
	this->posX = 0;
	this->posY = 0;
	widthOfSprite = 0;
	heightOfSprite = 0;
	coin = 0;

	shape.setRadius(21);
	shape.setFillColor(color);
	shape.setOutlineThickness(5.f);
	shape.setOutlineColor(sf::Color::Black);

	if (!font.loadFromFile(fontDir)) {
		exit(-10);
	}

	this->text.setFont(font);
	this->text.setString(text);

	if (color != sf::Color::Black)
		this->text.setFillColor(sf::Color::Black);
	else
		this->text.setFillColor(sf::Color::White);

	setCenteredText();
	this->text.setCharacterSize(20);
	shape.setPosition(posX, posY);
}

PokerButton::PokerButton(sf::Color color, std::string fontDir, int totalCoins)
{
	this->posX = 0;
	this->posY = 0;
	widthOfSprite = 0;
	heightOfSprite = 0;
	coin = totalCoins;

	shape.setRadius(21);
	shape.setFillColor(color);
	shape.setOutlineThickness(5.f);
	shape.setOutlineColor(sf::Color::Black);

	if (!font.loadFromFile(fontDir)) {
		exit(-10);
	}
	this->text.setFont(font);
	this->text.setString(std::to_string(totalCoins));

	if (color != sf::Color::White)
		this->text.setFillColor(sf::Color::White);
	else
		this->text.setFillColor(sf::Color::Black);

	setCenteredText();
	this->text.setCharacterSize(20);
	shape.setPosition(posX, posY);
}

PokerButton::~PokerButton()
{

}

void PokerButton::setCenteredText()
{
	sf::FloatRect textBound = text.getLocalBounds();
	text.setOrigin(textBound.left + textBound.width / 2.0f, textBound.top + textBound.height / 2.0f);
	text.setPosition(posX + widthOfSprite / 2.f, posY + heightOfSprite / 2.f);
}

void PokerButton::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}

void PokerButton::setPosition(float posX, float posY)
{
	shape.setPosition(posX, posY);
	text.setPosition(posX + 50.f / 2.f, posY + 50.f / 2.f);
}

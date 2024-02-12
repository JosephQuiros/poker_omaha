#include "BetSystem.h"

BetSystem::BetSystem(List* list, Dealer* dealer)
{	
	playerList = list;
	this->dealer = dealer;
	posX = 0;
	posY = 0;
	width = 345;
	height = 200;
	lastBet = 4;
	visible = false;
	
	background.setSize(sf::Vector2f(width, height));
	background.setFillColor(sf::Color::Green);
	background.setOutlineThickness(5);
	background.setOutlineColor(sf::Color::Black);
	background.setPosition(posX, posY);

	if (!font.loadFromFile("Fonts/times.ttf")) {
		std::cout << "error";
		exit(-10);
	}
	text.setFont(font);
	text.setString("last bet: 4");
	text.setFillColor(sf::Color::Black);
	text.setPosition(posX + 8.f, posY + 8.f);
	createButtons();
}

BetSystem::~BetSystem()
{
	int i;

	for (i = 0; i < MAX_BUTTONS; i++) {
		delete buttonArray[i];
	}

}

void BetSystem::drawOnWindow(sf::RenderWindow& window)
{
	if (visible) {
		window.draw(background);
		window.draw(text);
		int i;
		for (i = 0; i < MAX_BUTTONS; i++) {
			buttonArray[i]->draw(window);
		}
	}
}

bool BetSystem::isVisible()
{
	return visible;
}

void BetSystem::setVisible(bool visible)
{
	int i;
	this->visible = visible;

	for (i = 0; i < MAX_BUTTONS; i++) {
		buttonArray[i]->setVisibility(visible);
	}

}

void BetSystem::setPosition(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;

	background.setPosition(posX, posY);
	text.setPosition(posX + 8.f, posY + 8.f);
	buttonArray[0]->setPostion((posX + width) - 108.f, posY + 8.f);
	buttonArray[1]->setPostion((posX + width) - 108.f, posY + 66.f);
}

int BetSystem::findTheButtonPressed(sf::Vector2f& mousePos)
{
	int i;
	for (i = 0; i < MAX_BUTTONS; i++) {
		if (buttonArray[i]->isPressed(mousePos)) {
			return i;
		}
	}
	return -1;
}

void BetSystem::whatButtonWasPressed(sf::Vector2f& mousePos, int& turnPlayer, int& numPlayers,int& numRound ,Player*& currentPlayer)
{
	switch (findTheButtonPressed(mousePos))
	{
	case -1:
		std::cout << "no preciono ningun boton en betWindow\n";
		break;
	case 0:
		if (currentPlayer->getCoins()->getAmountOfCoins() >= lastBet) {
			call(currentPlayer);
			nextTurn(turnPlayer, numPlayers, numRound ,currentPlayer);
		}
		
		break;
	case 1:
		if (currentPlayer->getCoins()->getAmountOfCoins() >= lastBet * 2) {
			raise(currentPlayer);
			nextTurn(turnPlayer, numPlayers, numRound,currentPlayer);
		}
		break;
	default:
		break;
	}

}

void BetSystem::createButtons()
{
	buttonArray[0] = new RectangleButton(100.f, 50.f, "CALL", "Fonts/times.ttf");
	buttonArray[1] = new RectangleButton(100.f, 50.f, "RAISE", "Fonts/times.ttf");

	buttonArray[0]->setPostion((posX + width) - 108.f, posY + 8.f);
	buttonArray[1]->setPostion((posX + width) - 108.f, posY + 66.f);

}

void BetSystem::nextTurn(int& turnPlayer, int& numPlayers, int& numRound,Player*& currentPlayer)
{
	setVisible(false);
	currentPlayer->setCardIsVisible(false);
	if (turnPlayer < numPlayers) {
		turnPlayer++;
		currentPlayer = playerList->getPlayer(turnPlayer);
	}
	else {
		dealer->takeCard(1);
		turnPlayer = 1;
		numRound++;
		currentPlayer = playerList->getPlayer(turnPlayer);
	}


}

void BetSystem::call(Player*& currentPlayer)
{
	currentPlayer->getCoins()->subtractAmountOfCoins(lastBet);
	dealer->getPot()->addAmountOfCoins(lastBet);
}

void BetSystem::raise(Player*& currentPlayer)
{
	lastBet *= 2;
	text.setString("last bet: " + std::to_string(lastBet));
	currentPlayer->getCoins()->subtractAmountOfCoins(lastBet);
	dealer->getPot()->addAmountOfCoins(lastBet);
}

void BetSystem::restart()
{
	lastBet = 4;
	text.setString("last bet: " + std::to_string(lastBet));
}

#include "Player.h"

Player::Player(int idPlayer)
{
	int i;
	numCardsOnDeck = 0;
	posX = 0.f;
	posY = 0.f;
	cardIsVisible = false;
	inGame = true;
	coins = new PokerButton(sf::Color::Blue, "Fonts/times.ttf", 80);

	setIdPlayer(idPlayer);

	for (i = 0; i < MAX_CARDS; i++) {
		ownDeck[i] = nullptr;
	}

	for (i = 0; i < MAX_BUTTONS; i++) {
		pokerButtons[i] = nullptr;
	}
}

Player::~Player()
{
}

void Player::takeCard(Card* card)
{
	if (numCardsOnDeck < MAX_CARDS) {
		ownDeck[numCardsOnDeck] = card;
		card->setPostions(posX + numCardsOnDeck * 72, posY);
		numCardsOnDeck++;
	}
}

void Player::returnCardToDeck()
{
	int i;

	for (i = 0; i < numCardsOnDeck; i++) {
		ownDeck[i] = nullptr;
	}
	numCardsOnDeck = 0;
}

void Player::drawOnWindow(sf::RenderWindow& window)
{	

	if (inGame) {
		int i;
		coins->draw(window);

		if (cardIsVisible) 
		{
			for (i = 0; i < numCardsOnDeck; i++) {
				window.draw(ownDeck[i]->getFrontSprite());
			}
			
		}
		else 
		{
			for (i = 0; i < numCardsOnDeck; i++) {
				window.draw(ownDeck[i]->getBackSprite());
			}
		}
		

		for (i = 0; i < MAX_BUTTONS; i++) {
			if (pokerButtons[i] != nullptr) {
				pokerButtons[i]->draw(window);
			}
		}

		window.draw(id);
	}
	
}

void Player::setPosition(float posX, float posY)
{
	id.setPosition(posX, posY);

	sf::FloatRect textBounds = id.getGlobalBounds();
	this->posX =posX + textBounds.width + 20;
	this->posY = posY;
	

	if (numCardsOnDeck >= 1) {
		int i;
		for (i = 0; i < numCardsOnDeck; i++) {
			ownDeck[i]->setPostions(posX + i * 72, posY);
		}
	}

	
	coins->setPosition(posX, posY + 30);

}

void Player::takePokerButton(PokerButton* pokerButton)
{
	int i;
	for (i = 0; i < MAX_BUTTONS; i++) {

		if (pokerButtons[i] == nullptr) {
			pokerButtons[i] = pokerButton;

			if (i == 0)
				pokerButton->setPosition(posX + (MAX_CARDS * 72) + 5.f,posY);
			else
				pokerButton->setPosition(posX + (MAX_CARDS * 72) + 5.f, posY + 55.f);
			return;
		}
	}
}

bool Player::isCardVisible()
{
	return cardIsVisible;
}

PokerButton* Player::getCoins()
{
	return coins;
}

void Player::setCardVisible(bool visible)
{
	this->cardIsVisible = visible;
}

void Player::setInGame(bool inGame)
{
	this->inGame = inGame;
}

bool Player::isInGame()
{
	return inGame;
}

bool Player::haveCards()
{
	if (numCardsOnDeck > 1) {
		return true;
	}
	return false;
}

void Player::returnPokerButton()
{
	int i;

	for (i = 0; i < MAX_BUTTONS; i++) {
		pokerButtons[i] = nullptr;
	}
}

bool Player::haveIPokerButton(PokerButton* button)
{
	int i;
	for (i = 0; i < MAX_BUTTONS; i++) {
		if (pokerButtons[i] == button) {
			return true;
		}
	}
	return false;
}

std::string Player::getId()
{
	return id.getString();
}

Card* Player::getCard(int position)
{
	if (position < MAX_CARDS && position > -1)
	{
		return ownDeck[position];
	}
	return nullptr;
}

void Player::setIdPlayer(int idPlayer)
{
	if (!font.loadFromFile("Fonts/times.ttf"))
	{
		exit(-10);
	}
	id.setFont(font);
	id.setCharacterSize(20);
	id.setFillColor(sf::Color::Black);
	id.setPosition(posX + (MAX_CARDS * 72.f) + 40.f, posY);
	id.setString("Player " + std::to_string(idPlayer));
}

int Player::getPointOfHand(Card**& communityDeck)
{
	int actualPoints = 0;
	int newPoints;

	newPoints = onePair(communityDeck);
	if (actualPoints < newPoints) {
		actualPoints = newPoints;
	}

	return actualPoints;
}

int Player::onePair(Card**& communityDeck)
{

	int maxIndex = 0;

	int i, j;

	for (i = 0; i < MAX_CARDS - 1; i++) {

		for (j = i + 1; j < MAX_CARDS; j++) {
			if (maxIndex < ownDeck[i]->getIndex()) {
				if (ownDeck[i]->getIndex() == ownDeck[j]->getIndex()) {
					maxIndex = ownDeck[i]->getIndex();
				}
			}
		}
	}

	for (i = 0; i < 5 - 1; i++) {

		for (j = i + 1; j < 5; j++) {
			if (maxIndex < communityDeck[i]->getIndex()) {
				if (communityDeck[i]->getIndex() == communityDeck[j]->getIndex()) {
					maxIndex = communityDeck[i]->getIndex();
				}
			}
		}
	}

	for (i = 0; i < MAX_CARDS - 1; i++) {

		for (j = 0; j < 5; j++) {
			if (maxIndex < ownDeck[i]->getIndex()) {
				if (ownDeck[i]->getIndex() == communityDeck[j]->getIndex()) {
					maxIndex = ownDeck[i]->getIndex();
				}
			}
		}
	}

	if (maxIndex != 0) {
		return 100 + maxIndex;
	}

	return maxIndex;
}

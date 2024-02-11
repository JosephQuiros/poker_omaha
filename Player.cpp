#include "Player.h"

Player::Player(int idPlayer)
{
	int i;
	numCardsOnDeck = 0;
	posX = 0.f;
	posY = 0.f;
	cardIsVisible = false;
	isInGame = true;
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

	if (isInGame) {
		int i;

		if (cardIsVisible) {
			for (i = 0; i < numCardsOnDeck; i++) {
				window.draw(ownDeck[i]->getFrontSprite());
			}
		}


		else {
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
		coins->draw(window);
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

bool Player::CardIsVisible()
{
	return cardIsVisible;
}

void Player::setCardIsVisible(bool visible)
{
	this->cardIsVisible = visible;
}

void Player::setIsInGame(bool isInGame)
{
	this->isInGame = isInGame;
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
	id.setString("Jugador " + std::to_string(idPlayer));
}

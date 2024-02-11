#include "Poker.h"

Poker::Poker(int numPlayers)
{
	this->numPlayers = numPlayers;
	dealer = new Dealer();
	playerList = new List(numPlayers);
	createWindow();
	createbutton();
	setPlayerAndDealerPosition();
}

Poker::~Poker()
{
	int i;
	std::cout << "destruir poker\n";
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		delete buttonArray[i];
	}
	delete playerList;
	delete dealer;
}

void Poker::createWindow()
{
	window.create(sf::VideoMode(1752, 944), "Poker");
	window.setPosition(sf::Vector2i(50, 10));
	texture.loadFromFile("mesaFondo.jpg");
	background.setTexture(texture);
}

void Poker::setPlayerAndDealerPosition()
{
	float positionXToDealer = 650.f;
	float positionYToDealer = 410.f;
	float positionXToPlayer[6] = { 420.f, 420.f, 880.f, 880.f, 570.f, 920.f };
	float positionYToPlayer[6] = { 40.f, 810.f, 40.f, 810.f, 400.f, 400.f };

	playerList->setPositionToPlayers(positionXToPlayer, positionYToPlayer, 6 ,6);
	dealer->setPosition(positionXToDealer, positionYToDealer);
}

void Poker::drawButtons()
{
	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		buttonArray[i]->draw(window);
	}
}

void Poker::createbutton()
{
	buttonArray[0] = new RectangleButton(150.f, 50.f, "SHOW", "Fonts/times.ttf");
	buttonArray[1] = new RectangleButton(200.f, 50.f, "WITHDRAW", "Fonts/times.ttf");
	buttonArray[2] = new RectangleButton(120.f, 50.f, "BET", "Fonts/times.ttf");

	buttonArray[0]->setPostion(1257.f, 889.f);
	buttonArray[1]->setPostion(1417.f, 889.f);
	buttonArray[2]->setPostion(1627.f, 889.f);

	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		buttonArray[i]->setVisibility(true);
	}
}

void Poker::dealCardsToPlayers()
{
	int i, j, numCards = 4;
	Player* aux;

	for (i = 1; i <= numPlayers; i++) {
		aux = playerList->getPlayer(i);

		for (j = 0; j < numCards; j++) {
			dealer->dealCard(aux);
		}
	}
}

void Poker::preGame()
{
	playersInThisRound = numPlayers;
	turnPlayer = 1;
	dealer->shuffleDeck();
	dealCardsToPlayers();
	dealer->takeCard(3);
	dealer->dealPokerButton(playerList->getPlayer(1), 1);
	dealer->dealPokerButton(playerList->getPlayer(2), 2);
	dealer->dealPokerButton(playerList->getPlayer(2), 3);
	currentPlayer = playerList->getPlayer(turnPlayer);
}

void Poker::postGame()
{
	playerList->returnTheirCardsToDeck();
	dealer->returnCommunityCardsToDeck();
	window.setVisible(true);
}

void Poker::play()
{

	for(int i = 0; i < 3; i++) {
		preGame();
		loop();
		postGame();
	}

}

void Poker::loop()
{

	while (window.isOpen() && playersInThisRound >=2)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.setVisible(false);
				return;
			}

			if (event.type == sf::Event::KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { //debug
					sf::Vector2i mousePos;

					mousePos = sf::Mouse::getPosition(window);
					std::cout << "pos X: " << mousePos.x << ".   Pos Y: " << mousePos.y << std::endl;
				}//debug

			}

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					whatButtonWasPressed(mousePos);
				}
			}
		}

		update();

		draw();
	}
}

void Poker::update()
{
}

void Poker::draw()
{
	window.clear();
	window.draw(background);
	drawButtons();
	playerList->drawPlayers(window);
	dealer->drawCards(window);
	window.display();
}

int Poker::findTheButtonPressed(sf::Vector2f& mousePos)
{
	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		if (buttonArray[i]->isPressed(mousePos)) {
			return i;
		}
	}
	return -1;
}

void Poker::whatButtonWasPressed(sf::Vector2f mousePos)
{
	switch (findTheButtonPressed(mousePos))
	{
	case -1:
		std::cout << "no preciono ningun boton\n";
		break;

	case 0:
		if (currentPlayer->CardIsVisible())
			currentPlayer->setCardIsVisible(false);
		else
			currentPlayer->setCardIsVisible(true);
		break;

	case 1:
		currentPlayer->setIsInGame(false);
		playersInThisRound--;
		if (turnPlayer < numPlayers) {
			turnPlayer++;
			currentPlayer = playerList->getPlayer(turnPlayer);

		}
		else {
			dealer->takeCard(1);
			turnPlayer = 1;
			currentPlayer = playerList->getPlayer(turnPlayer);
			
		}
		break;

	case 2:
		currentPlayer->setCardIsVisible(false);

		if (turnPlayer < numPlayers) {
			turnPlayer++;
			currentPlayer = playerList->getPlayer(turnPlayer);
		}
		else {
			dealer->takeCard(1);
			turnPlayer = 1;
			currentPlayer = playerList->getPlayer(turnPlayer);
		}
		break;

	default:
		break;
	}

}

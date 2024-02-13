#include "Poker.h"

Poker::Poker(int numPlayers)
{
	dealer = new Dealer();
	playerList = new List(numPlayers);
	this->numPlayers = numPlayers;
	numPlayersInThisRound = numPlayers;
	betWindow = new BetSystem(playerList, dealer);
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
	delete betWindow;
	delete playerList;
	delete dealer;
	
}

void Poker::createWindow()
{
	window.create(sf::VideoMode(1752, 944), "Poker");

	window.setFramerateLimit(60);
	countdownSeconds = 20;
	

	window.setPosition(sf::Vector2i(50, 10));
	texture.loadFromFile("mesaFondo.jpg");
	background.setTexture(texture);
}

void Poker::setPlayerAndDealerPosition()
{
	float positionXToDealer = 650.f;
	float positionYToDealer = 410.f;
	float positionXToPlayer[6] = { 420.f, 880.f, 880.f, 420.f, 570.f, 920.f };
	float positionYToPlayer[6] = { 40.f, 40.f ,810.f, 810.f, 400.f, 400.f };

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
	buttonArray[1] = new RectangleButton(200.f, 50.f, "FOLD", "Fonts/times.ttf");
	buttonArray[2] = new RectangleButton(120.f, 50.f, "BET", "Fonts/times.ttf");

	buttonArray[0]->setPostion(1257.f, 889.f);
	buttonArray[1]->setPostion(1417.f, 889.f);
	buttonArray[2]->setPostion(1627.f, 889.f);

	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		buttonArray[i]->setVisibility(true);
	}

	betWindow->setPosition(1400, 665);

	if (!fontClock.loadFromFile("Fonts/times.ttf")) exit(-1);

	textClock.setFont(fontClock);
	textClock.setString("Time: ");
	textClock.setPosition(20.f, 20.f);
	textClock.setFillColor(sf::Color::Black);

}

void Poker::dealCardsToPlayers()
{
	int i, j, numCards = 4;
	Player* actualPlayer;

	for (i = 1; i <= numPlayers; i++)
	{
		actualPlayer = playerList->getPlayer(i);

			for (j = 0; j < numCards; j++) {
				dealer->dealCard(actualPlayer);
			}
	}
}

void Poker::preGame()
{
	playerList->dealPokerButtonsToPlayers(dealer->getPokerButtons());
	dealer->shuffleDeck();
	prefloop();
	dealCardsToPlayers();
	dealer->takeCard(2);
	
}

void Poker::prefloop()
{
	getBet(1, 2);
	getBet(2, 4);
	turnPlayer = playerList->findPlayerNextToBigBlind(dealer->getPokerButton(2));
	currentPlayer = playerList->getPlayer(turnPlayer);
	loop(1);
}

void Poker::postGame()
{
	system("cls");
	std::cout << "estoy aca\n";
	Player* winner = playerList->findWinner(dealer->getCommunityDeck(), numPlayersInThisRound);
	//winner->getCoins()->addAmountOfCoins(dealer->getPot()->getAmount());
	dealer->getPot()->setAmountOfCoins(0);
	betWindow->restart();
	playerList->returnTheirCardsToDeck();
	dealer->returnCommunityCardsToDeck();
	playerList->returnPokerButton();
	playerList->findPlayersAvailableToPlay();
	numPlayers = playerList->getTotalPlayer();
	numPlayersInThisRound = numPlayers;
}

void Poker::getBet(int player, int amount)
{
	playerList->getPlayer(player)->getCoins()->subtractAmountOfCoins(amount);
	dealer->getPot()->addAmountOfCoins(amount);
}

void Poker::startClock()
{
	startTime = clock.getElapsedTime();
}

void Poker::play()
{

	while(window.isOpen() && numPlayers >= 2)
	{
		if(window.isOpen())
			preGame();
		if (window.isOpen())
			loop(3);
		if (window.isOpen())
			postGame();
	}

}

void Poker::loop(int iterations)
{
	numRounds = 0;

	startClock();
	while (window.isOpen() && numPlayersInThisRound >=2 && numRounds < iterations)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}

			if (event.type == sf::Event::KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { //debug
	
				}//debug

			}

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					whatButtonWasPressed(mousePos);

					if (betWindow->isVisible()) {
						betWindow->whatButtonWasPressed(mousePos,turnPlayer, numPlayers, numRounds, currentPlayer);
					}

				}
			}
		}

		update();

		draw();
	}
}

void Poker::update()
{
	sf::Time currentTime = clock.getElapsedTime();
	sf::Time elapsedTime = currentTime - startTime;
	int elapsedSeconds = elapsedTime.asSeconds();
	
	int remainingSeconds = countdownSeconds - elapsedSeconds;

	if (remainingSeconds == 0) 
	{
		currentPlayer->setInGame(false); //pafuera
		numPlayersInThisRound - 1;

		if (turnPlayer < numPlayers) {
			turnPlayer++;
			currentPlayer = playerList->getPlayer(turnPlayer);

		}
		else {
			dealer->takeCard(1);
			turnPlayer = 1;
			currentPlayer = playerList->getPlayer(turnPlayer);
			numRounds++;
		}
		startClock();
	}

	textClock.setString("TIME \n  " + std::to_string(remainingSeconds));
	
}

void Poker::draw()
{
	window.clear();
	window.draw(background);

	window.draw(textClock);
	
	drawButtons();
	playerList->drawPlayers(window);
	dealer->drawCards(window);
	betWindow->drawOnWindow(window);
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

void Poker::whatButtonWasPressed(sf::Vector2f& mousePos)
{
	switch (findTheButtonPressed(mousePos))
	{
	case -1:
	//	std::cout << "no preciono ningun boton\n";
		break;

	case 0:

		if (currentPlayer->CardIsVisible())
			currentPlayer->setCardIsVisible(false);
		else
			currentPlayer->setCardIsVisible(true);
		break;

	case 1:
		startClock();

		currentPlayer->setInGame(false);
		numPlayersInThisRound--;

		if (turnPlayer < numPlayers) {
			turnPlayer++;
			currentPlayer = playerList->getPlayer(turnPlayer);

		}
		else {
			dealer->takeCard(1);
			turnPlayer = 1;
			currentPlayer = playerList->getPlayer(turnPlayer);
			numRounds++;
		}
		break;

	case 2:
		
		if (betWindow->isVisible()) {
			betWindow->setVisible(false);
			startClock();
		}
				
		else{
			betWindow->setVisible(true);
			startClock();
		}
		
		break;

	default:
		break;
	}

}

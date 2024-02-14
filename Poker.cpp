#include "Poker.h"

Poker::Poker(int numPlayers)
{
	dealer = new Dealer();
	playerList = new List(numPlayers);
	this->numPlayers = numPlayers;
	numPlayersInThisRound = numPlayers;
	createWindow();
	createButton();
	setPlayerAndDealerPosition();
	saveFile.open("match.txt");
	numRound = 1;
}

Poker::~Poker()
{
	saveFile << "El juego termino";
	saveFile.close();
	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		delete buttonArray[i];
	}
	delete playerList;
	delete dealer;	
}

void Poker::createWindow()
{
	window.create(sf::VideoMode(1752, 944), "Poker");

	window.setFramerateLimit(60);
	countdownSeconds = 40;
	window.setPosition(sf::Vector2i(50, 10));
	texture.loadFromFile("mesaFondo.jpg");
	background.setTexture(texture);
}

void Poker::setPlayerAndDealerPosition()
{
	float positionXToDealer = 650.f;
	float positionYToDealer = 410.f;
	float positionXToPlayer[6] = { 420.f, 880.f,1300.f, 880.f, 420.f,5.f };
	float positionYToPlayer[6] = { 40.f, 40.f,410.f, 810.f, 810.f,410.f };

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

void Poker::createButton()
{
	buttonArray[0] = new RectangleButton(150.f, 50.f, "SHOW", "Fonts/times.ttf");
	buttonArray[1] = new RectangleButton(200.f, 50.f, "FOLD", "Fonts/times.ttf");
	buttonArray[2] = new RectangleButton(120.f, 50.f, "CALL", "Fonts/times.ttf");
	buttonArray[3] = new RectangleButton(120.f, 50.f, "RISE", "Fonts/times.ttf");

	buttonArray[0]->setPostion(1257.f, 889.f);
	buttonArray[1]->setPostion(1417.f, 889.f);
	buttonArray[2]->setPostion(1627.f, 829.f);
	buttonArray[3]->setPostion(1627.f, 889.f);

	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		buttonArray[i]->setVisibility(true);
	}

	if (!font.loadFromFile("Fonts/times.ttf")) exit(-1);

	textClock.setFont(font);
	textClock.setString("Time: ");
	textClock.setPosition(20.f, 20.f);
	textClock.setFillColor(sf::Color::Black);

	text[0].setFont(font);
	text[0].setString("Last bet: 4");
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(800, 590);

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(765, 550);

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
	saveNumPlayersInthisGame();
	playerList->dealPokerButtonsToPlayers(dealer->getPokerButtons());
	savePlayersWithPokerButton();
	dealer->shuffleDeck();
	prefloop();
	dealCardsToPlayers();
	saveFile << "El dealer reparte las cartas a los jugadores" << std::endl;
	makeEndLine(2);
	saveFile << "Inicia el floop";
	makeEndLine(2);
	dealer->takeCard(2);
	saveCardsOfPlayer(currentPlayer);
}

void Poker::prefloop()
{
	saveFile << "Inicio del prefloop" << std::endl;
	getBet(1, 2);
	saveFile << playerList->getPlayer(1)->getId() << ": " << "apuesta 2 fichas para iniciar la ronda" << std::endl;
	getBet(2, 4);
	saveFile << playerList->getPlayer(2)->getId() << ": " << "dobla la apuesta de la little blind" << std::endl;
	lastBet = 4;
	turnPlayer = playerList->findPlayerNextToBigBlind(dealer->getPokerButton(2));
	currentPlayer = playerList->getPlayer(turnPlayer);
	restartTextOfCurrentPlayer();
	prefloopLoop();
}

void Poker::postGame()
{
	system("cls");
	Player* winner = playerList->findWinner(dealer->getCommunityDeck(), numPlayersInThisRound);
	saveFile << "El ganador de la ronda es el " << winner->getId()<<std::endl;
	saveFile << "El ganador se lleva el pote de " << dealer->getPot()->getAmountOfCoins() <<" fichas."<<std::endl;
	saveFile << "-------------------fin de la partida----------------------------------" << std::endl;
	makeEndLine(2);
	winner->getCoins()->addAmountOfCoins(dealer->getPot()->getAmountOfCoins());
	dealer->getPot()->setAmountOfCoins(0);
	restartTextOfLastBet();
	playerList->returnTheirCardsToDeck();
	dealer->returnCommunityCardsToDeck();
	playerList->returnPokerButton();
	playerList->findPlayersAvailableToPlay();
	numRound++;
	numPlayers = playerList->getTotalPlayer();
	numPlayersInThisRound = numPlayers;
}

void Poker::getBet(int player, int amount)
{
	playerList->getPlayer(player)->getCoins()->subtractAmountOfCoins(amount);
	dealer->getPot()->addAmountOfCoins(amount);
}

void Poker::restartClock()
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
			gameLoop();
		if (window.isOpen())
			postGame();
	}

}

void Poker::prefloopLoop()
{
	buttonArray[0]->setVisibility(false);
	totalRounds = 0;

	restartClock();
	while (window.isOpen() && numPlayersInThisRound >= 2 && totalRounds < 1)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				fileWasCloseInGame();
				return;
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

void Poker::gameLoop()
{
	buttonArray[0]->setVisibility(true);
	totalRounds = 0;

	restartClock();
	while (window.isOpen() && numPlayersInThisRound >=2 && totalRounds < 3)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				fileWasCloseInGame();
				return;
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
	sf::Time currentTime = clock.getElapsedTime();
	sf::Time elapsedTime = currentTime - startTime;
	int elapsedSeconds = elapsedTime.asSeconds();
	
	int remainingSeconds = countdownSeconds - elapsedSeconds;

	if (remainingSeconds == 0) 
	{
		saveFile << currentPlayer->getId() << " se ha quedado sin tiempo y ha sido expulsado de la mesa";
		makeEndLine(2);
		currentPlayer->setInGame(false); 
		numPlayersInThisRound--;
		nextTurn();
		restartClock();
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
	window.draw(text[1]);
	window.draw(text[0]);
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
		break;

	case 0:

		if (currentPlayer->isCardVisible())
			currentPlayer->setCardVisible(false);
		else
			currentPlayer->setCardVisible(true);
		break;

	case 1:
		restartClock();

		currentPlayer->setInGame(false);
		numPlayersInThisRound--;
		nextTurn();

		break;

	case 2:
		if (currentPlayer->getCoins()->getAmountOfCoins() >= lastBet) {
			call();
			nextTurn();
		}
		break;

	case 3:
		if (currentPlayer->getCoins()->getAmountOfCoins() >= lastBet * 2) {
			raise();
			nextTurn();
		}
		break;

	default:
		break;
	}

}

void Poker::nextTurn()
{
	currentPlayer->setCardVisible(false);
	if (turnPlayer < numPlayers) {
		turnPlayer++;
		currentPlayer = playerList->getPlayer(turnPlayer);
		saveCardsOfPlayer(currentPlayer);
		restartTextOfCurrentPlayer();
	}
	else {
		dealer->takeCard(1);
		turnPlayer = 1;
		saveFile << "fin de esta ronda" << std::endl;
		makeEndLine(2);
		totalRounds++;
		currentPlayer = playerList->getPlayer(turnPlayer);
		saveCardsOfPlayer(currentPlayer);
		restartTextOfCurrentPlayer();
	}


}

void Poker::call()
{
	restartClock();
	saveFile << currentPlayer->getId() << " apuesta " << lastBet << " fichas" << std::endl;
	makeEndLine(2);
	currentPlayer->getCoins()->subtractAmountOfCoins(lastBet);
	dealer->getPot()->addAmountOfCoins(lastBet);

}

void Poker::raise()
{
	restartClock();
	lastBet *= 2;
	saveFile << currentPlayer->getId()<<" apuesta " << lastBet << " fichas" << std::endl;
	makeEndLine(2);
	text[0].setString("Last bet: " + std::to_string(lastBet));
	currentPlayer->getCoins()->subtractAmountOfCoins(lastBet);
	dealer->getPot()->addAmountOfCoins(lastBet);
}

void Poker::restartTextOfLastBet()
{
	lastBet = 4;
	text[0].setString("Last bet: " + std::to_string(lastBet));
}

void Poker::restartTextOfCurrentPlayer()
{
	text[1].setString("Turn of: " + currentPlayer->getId());
}

void Poker::makeEndLine(int iterations)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		saveFile << std::endl;
	}
}

Player* Poker::findPokerButtonInPlayer(PokerButton* button)
{
	int i = 1;
	Player* aux = playerList->getPlayer(i);

	while (!aux->haveIPokerButton(button)) {
		i++;
		aux = playerList->getPlayer(i);
	}

	return aux;
}

void Poker::saveNumPlayersInthisGame()
{
	saveFile << "Numero de Ronda:" << numRound << std::endl;
	saveFile << "Jugadores para esta ronda:" << numPlayers << std::endl;
	makeEndLine(1);
}

void Poker::savePlayersWithPokerButton()
{
	Player* aux = nullptr;
	PokerButton** pokerButtonsArray = dealer->getPokerButtons();

	saveFile << "Jugadores con los Poker Buttons:" << std::endl;

	aux = findPokerButtonInPlayer(pokerButtonsArray[0]);
	saveFile << aux->getId() << ": " << "Dealer" << std::endl;

	aux = findPokerButtonInPlayer(pokerButtonsArray[1]);
	saveFile << aux->getId() << ": " << "Little Blind" << std::endl;

	aux = findPokerButtonInPlayer(pokerButtonsArray[2]);
	saveFile << aux->getId() << ": " << "Big Blind" << std::endl;

	makeEndLine(1);
}

void Poker::saveCardsOfPlayer(Player* player)
{
	if (currentPlayer->haveCards()&& currentPlayer->isInGame() && dealer->haveCards())
	{
		int i;
		int numOfCard;
		Card* aux;
		saveFile << player->getId() << " tiene las cartas:" << std::endl;

		for (i = 0; i < 4; i++) {
			aux = player->getCard(i);
			numOfCard = aux->getIndex();

			if (numOfCard < 11) {
				saveFile << aux->getIndex() << " de ";
			}

			if (numOfCard == 11) {
				saveFile << 'J' << " de ";
			}

			if (numOfCard == 12) {
				saveFile << 'Q' << " de ";
			}

			if (numOfCard == 13) {
				saveFile << 'K' << " de ";
			}

			if (numOfCard == 14) {
				saveFile << 'A' << " de ";
			}

			switch (aux->getSuit())
			{
			case 0:
				saveFile << "Clubs" << std::endl;
				break;
			case 1:
				saveFile << "Diamonds" << std::endl;
				break;
			case 2:
				saveFile << "Hearts" << std::endl;
				break;
			case 3:
				saveFile << "Spades" << std::endl;
				break;
			default:
				break;
			}
		}
		saveCommunityCards(dealer->getCommunityDeck());
	}
}

void Poker::saveCommunityCards(Card** communityCards)
{
	if (dealer->haveCards())
	{
		int i;
		int numOfCard;
		Card* aux;
		saveFile << "En la mesa hay: " << std::endl;

		for (i = 0; i < dealer->getnumOfCommunityDeck(); i++) {
			aux = communityCards[i];
			numOfCard = aux->getIndex();

			if (numOfCard < 11) {
				saveFile << aux->getIndex() << " de ";
			}

			if (numOfCard == 11) {
				saveFile << 'J' << " de ";
			}

			if (numOfCard == 12) {
				saveFile << 'Q' << " de ";
			}

			if (numOfCard == 13) {
				saveFile << 'K' << " de ";
			}

			if (numOfCard == 14) {
				saveFile << 'A' << " de ";
			}

			switch (aux->getSuit())
			{
			case 0:
				saveFile << "Clubs" << ". ";
				break;
			case 1:
				saveFile << "Diamonds" << ". ";
				break;
			case 2:
				saveFile << "Hearts" << ". ";
				break;
			case 3:
				saveFile << "Spades" << ". ";
				break;
			default:
				break;
			}
		}
		makeEndLine(1);
	}
}

void Poker::fileWasCloseInGame()
{
	saveFile << "El archivo fue cerrado en medio de la partida." << std::endl;
	makeEndLine(2);
}
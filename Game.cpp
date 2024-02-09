#include "Game.h"

Game::Game()
{
	dealer = new Dealer();
	playersArray = nullptr;
}

Game::~Game()
{

}

void Game::run()
{
	int numPlayer;

	do {
		numPlayer = mainMenu.selectNumPlayer();

		if (numPlayer != -1) {
			window.setVisible(true);
			playPoker(numPlayer);
			system("pause");
			window.close();
			mainMenu.getWindow()->setVisible(true);

		}

	} while (numPlayer != -1);

}

void Game::startGame(int numPlayers)
{
	createWindow();
	playersArray = new Player[numPlayers];
	setPlayerAndDealerPosition(numPlayers);
	dealCardsToPlayers(numPlayers);
	dealer->takeCard(3);
	createbutton();
}

void Game::createWindow()
{
	window.create(sf::VideoMode(1752, 944), "Poker");
	window.setPosition(sf::Vector2i(50, 10));
	texture.loadFromFile("mesaFondo.jpg");
	background.setTexture(texture);
}

void Game::setPlayerAndDealerPosition(int numPlayers)
{
	float positionToDealer[2] = { 650.f, 410.f };
	float positionXToPlayer[6] = { 570.f, 570.f, 920.f, 920.f, 0.f, 0.f };
	float positionYToPlayer[6] = { 40.f, 810.f, 40.f, 810.f, 0.f, 0.f };
	int i;

	for (i = 0; i < numPlayers; i++) {
		playersArray[i].setPosition(positionXToPlayer[i], positionYToPlayer[i]);
	}

	dealer->setPosition(positionToDealer[0], positionToDealer[1]);
}

void Game::drawPlayers(int numPlayers)
{
	int  i;
	for (i = 0; i < numPlayers; i++) {
		playersArray[i].drawCards(window);
	}
}

void Game::drawButtons()
{
	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		buttonArray[i]->draw(window);
	}
}

void Game::createbutton()
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

void Game::init()
{
}

void Game::dealCardsToPlayers(int numPlayers)
{
	int i, j, numCards = 4;

	for (i = 0; i < numPlayers; i++) {

		for (j = 0; j < numCards; j++) {
			dealer->dealCard(playersArray[i]);
		}
	}
}

void Game::playPoker(int numPlayers)
{
	startGame(numPlayers);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { //debug
					sf::Vector2i mousePos;

					mousePos = sf::Mouse::getPosition(window);
					std::cout << "pos X: " << mousePos.x << ".   Pos Y: " << mousePos.y << std::endl;
				}//debug

			}
		}

		update();

		draw(numPlayers);
	}
}

void Game::update()
{
}

void Game::draw(int numPlayers)
{
	window.clear();
	window.draw(background);
	drawPlayers(numPlayers);
	dealer->drawCards(window);
	drawButtons();
	window.display();
}

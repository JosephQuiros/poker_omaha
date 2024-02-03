#include "Game.h"

Game::Game()
{
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

void Game::init(int numPlayers)
{
	actualCardDeck = 0;
	createWindow();
	deck.shuffle();
	playersArray = new Player[numPlayers];
	dealCardsToPlayers(numPlayers);

}

void Game::createWindow()
{
	window.create(sf::VideoMode(1752, 944), "Poker");
	texture.loadFromFile("mesaFondo.jpg");
	background.setTexture(texture);
}

void Game::dealCardsToPlayers(int numPlayers)
{
	int i;

	for (i = 0; i < numPlayers; i++)
	{

	}
}

void Game::playPoker(int numPlayers)
{
	init(numPlayers);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		update();

		draw();
	}
}

void Game::update()
{
}

void Game::draw()
{
	window.clear();
	window.draw(background);
	window.display();
}

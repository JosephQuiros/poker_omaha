#include "Game.h"

Game::Game()
{
	init();
	deck.shuffleDeck();
	carta = deck.getCard(0);

}

Game::~Game()
{
}

void Game::run()
{
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

void Game::init()
{
	window.create(sf::VideoMode(1752, 944), "Poker");
	
	texture.loadFromFile("mesaFondo.jpg");

	background.setTexture(texture);

}

void Game::update()
{
}

void Game::draw()
{
	window.clear();
	window.draw(background);
	window.draw(carta->getSprite());
	window.display();
}

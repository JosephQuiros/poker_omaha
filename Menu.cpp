#include "Menu.h"

Menu::Menu()
{
	numPlayers = 2;
	init();
}

Menu::~Menu()
{
	int i;
	
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		delete buttonArray[i];
	}

}

void Menu::init()
{
	window.create(sf::VideoMode(500, 600), "Poker");
	createButtons();
	optionMenu = 0;
}

void Menu::createButtons()
{
	int i;
	for (i = 0; i < 5 ; i++) {
		buttonArray[i] = new RectangleButton();
	}
	for (i = 5; i < TOTAL_BUTTONS; i++) {
		buttonArray[i] = new TriangleButton();
	}

	buttonArray[0]->create(200.f, 50.f, "PLAY", "Fonts/times.ttf");
	buttonArray[1]->create(200.f, 50.f, "ABOUT", "Fonts/times.ttf");
	buttonArray[2]->create(200.f, 50.f, "EXIT", "Fonts/times.ttf");
	buttonArray[3]->create(200.f, 50.f, "BACK", "Fonts/times.ttf");
	buttonArray[4]->create(200.f, 50.f, "CONTINUE", "Fonts/times.ttf");

	buttonArray[0]->setPostion(150.f, 230.f);
	buttonArray[1]->setPostion(150.f, 330.f);
	buttonArray[2]->setPostion(150.f, 430.f);
	buttonArray[3]->setPostion(0.f, 0.f);
	buttonArray[4]->setPostion(300.f, 550.f);

	//Triangular buttons

	buttonArray[6]->create(20.f);
	buttonArray[5]->create(20.f);

	buttonArray[5]->setPostion(380.f, 190.f);

	buttonArray[6]->setPostion(420.f, 290.f);
	buttonArray[6]->rotate(180);

}

int Menu::findTheButtonPresed(sf::Vector2f& mousePos)
{ 
	int i;
	for (i = 0; i < TOTAL_BUTTONS; i++) {
		if (buttonArray[i]->isPressed(mousePos)) {
			return i;
		}		
	}
	return -1;
}

void Menu::drawScene()
{
	if (optionMenu == 0) {

		buttonArray[0]->draw(window);
		buttonArray[1]->draw(window);
		buttonArray[2]->draw(window);

		return;
	}
	if (optionMenu == 1) {
		if(numPlayers<6)
		buttonArray[5]->draw(window);

		if(numPlayers>2)
		buttonArray[6]->draw(window);

		buttonArray[3]->draw(window);
		buttonArray[4]->draw(window);

		return;
	}
	if (optionMenu == 2) {
		return;
	}

}


void Menu::run()
{
	buttonArray[0]->setVisibility(true);
	buttonArray[1]->setVisibility(true);
	buttonArray[2]->setVisibility(true);

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

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					switch (findTheButtonPresed(mousePos))
					{
					case 0:
						optionMenu = 1;
						buttonArray[0]->setVisibility(false);
						buttonArray[1]->setVisibility(false);
						buttonArray[2]->setVisibility(false);
						buttonArray[3]->setVisibility(true);
						buttonArray[4]->setVisibility(true);
						buttonArray[5]->setVisibility(true);
						buttonArray[6]->setVisibility(true);

						break;
					case 1:

						break;
					case 2:
						window.close();
						break;

					case 3:
						optionMenu = 0;
						buttonArray[0]->setVisibility(true);
						buttonArray[1]->setVisibility(true);
						buttonArray[2]->setVisibility(true);
						buttonArray[3]->setVisibility(false);
						buttonArray[4]->setVisibility(false);
						buttonArray[5]->setVisibility(false);
						buttonArray[6]->setVisibility(false);
						break;

					case 4:
						window.close();
						break;

					case 5:
						if(numPlayers < 6)
						numPlayers++;
						std::cout << numPlayers<<"\n";

						break;
					case 6:
						if (numPlayers > 2)
						numPlayers--;
						std::cout << numPlayers<<"\n";
						break;

					default:
						break;
					}

				}
			}
		}

		update();

		draw();
	}
}

void Menu::update()
{
}

void Menu::draw()
{
	window.clear(sf::Color::Magenta);
	drawScene();
	window.display();
}
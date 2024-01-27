#include "Menu.h"

Menu::Menu()
{
	init();
}

Menu::~Menu()
{
}

void Menu::init()
{
	window.create(sf::VideoMode(500, 600), "Poker");
	rectanglebutton[0] = RectangleButton(200.f, 180.f, 100.f, 50.f, "Fonts/timesbd.ttf", "Hola");
	optionMenu = 0;
}

void Menu::run()
{
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
					if (rectanglebutton[0].isPressed(mousePos)) {
						std::cout << "me toco\n";
						std::cout << optionMenu << std::endl;
						optionMenu = 1;
						std::cout << optionMenu << std::endl;
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
	if (optionMenu == 0) {
		rectanglebutton[0].draw(window);
	}
	window.display();
}

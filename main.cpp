
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Deck.h"


int main()
{
    Deck deck;
    deck.shuffleDeck();
    deck.printCard();

    return 0;
}
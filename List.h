#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"
class List
{
private:
	Node* head;
	Node* aux;
	int numNodes;

public:
	List(int numPlayers);
	~List();
	void setPositionToPlayers(float positionXToPlayers[], float positionYToPlayers[], int sizeArrayX, int sizeArrayY);
	void drawPlayers(sf::RenderWindow& window);
	void findPlayersAvailableToPlay();
	void returnTheirCardsToDeck();
	void returnPokerButton();
	Player* getPlayer(int idPlayer);
	int getTotalPlayer();
	void dealPokerButtonsToPlayers(PokerButton** pokerButtons);
	int findPlayerNextToBigBlind(PokerButton* button);

private:
	void append(int idPlayer);
	void deleteNode(Node* node);
	void shiftLeftHead();
	
};
#endif // !LIST_H




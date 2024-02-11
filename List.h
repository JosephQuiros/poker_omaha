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
	void returnTheirCardsToDeck();
	Player* getPlayer(int idPlayer);

private:
	void append(int idPlayer);
	
};
#endif // !LIST_H




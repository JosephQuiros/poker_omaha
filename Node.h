#pragma once
#ifndef NODE_H
#define NODE_H

#include "Player.h"
class Node
{
private:
	Player* player;
	Node* next;

public:
	Node(Player* player);
	~Node();
	Player* getPlayer();
	Node* getNext();
	void setNext(Node* next);
};
#endif 




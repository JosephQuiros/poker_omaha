#include "Node.h"

Node::Node(Player* player)
{
	this->player = player;
	this->next = nullptr;
}

Node::~Node()
{
	delete player;
}

Player* Node::getPlayer()
{
	return player;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

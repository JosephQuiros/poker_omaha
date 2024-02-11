#include "List.h"

List::List(int numPlayers)
{
	head = nullptr;
	numNodes = 0;

	int i;
	for (i = 1; i <= numPlayers; i++) {
		append(i);
		numNodes++;
	}
}

List::~List()
{
	aux = head;

	while (aux != nullptr) {
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

void List::append(int idPlayer)
{
	Node* newNode = new Node(new Player(idPlayer));

	if (head == nullptr) {
		head = newNode;
		return;
	}

	aux = head;

	while (aux->getNext() != nullptr)
	{
		aux = aux->getNext();
	}

	aux->setNext(newNode);
}

void List::setPositionToPlayers(float positionXToPlayers[], float positionYToPlayers[], int sizeArrayX, int sizeArrayY)
{

	if (sizeArrayX % sizeArrayY == 0)
	{
		int i = 0;
		aux = head;
		while (aux != nullptr && i < sizeArrayX){
			aux->getPlayer()->setPosition(positionXToPlayers[i], positionYToPlayers[i]);
			i++;
			aux = aux->getNext();
		}
	}

	return;
}

void List::drawPlayers(sf::RenderWindow&  window)
{
	aux = head;

	while (aux != nullptr) {
		aux->getPlayer()->drawOnWindow(window);
		aux = aux->getNext();
	}
}

void List::returnTheirCardsToDeck()
{
	aux = head;

	while(aux != nullptr){
		Player* player = aux->getPlayer();
		player->returnCardToDeck();
		player->setIsInGame(true);
		player->setCardIsVisible(false);
		aux = aux->getNext();
	}
}

Player* List::getPlayer(int idPlayer)
{
	if (idPlayer <= 0 || idPlayer > numNodes)
		return nullptr;

	if (idPlayer <= numNodes) {
		int i;
		aux = head;
		for (i = 1; i < idPlayer; i++) {
			aux = aux->getNext();
		}
		return aux->getPlayer();
	}

	return nullptr;
}

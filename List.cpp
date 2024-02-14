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

void List::deleteNode(Node* node)
{
	numNodes--;
	Node* deleteAux = head;
	Node* prevNode = nullptr;

	while (deleteAux != node) {
		prevNode = deleteAux;
		deleteAux = deleteAux->getNext();
	}

	if (prevNode == nullptr) {
		head = deleteAux->getNext();
		delete deleteAux;
		return;
	}

	if (deleteAux->getNext() != nullptr) {
		prevNode->setNext(deleteAux->getNext());
		delete deleteAux;
		return;
	}

	prevNode->setNext(nullptr);
	delete deleteAux;
	return;
}

void List::findPlayersAvailableToPlay() {
	Player* actualPlayer;
	int node = 1;
	bool headWasDeleted = false;
	int minimumAmounToPlay = 20;

	aux = head;

	while (aux != nullptr) {
		actualPlayer = aux->getPlayer();

		if (actualPlayer->getCoins()->getAmountOfCoins() >= minimumAmounToPlay) {
			actualPlayer->setInGame(true);
			aux = aux->getNext();
		}
		else {
			if (node == 1) {
				headWasDeleted = true;
				deleteNode(aux);		
			}
			else {
				deleteNode(aux);
			}
			aux = head;
		}

		node++;
	}
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
	Player* player;

	while(aux != nullptr){
		player = aux->getPlayer();

		player->returnCardToDeck();
		player->setInGame(true);
		player->setCardIsVisible(false);
		aux = aux->getNext();
	}
}

void List::returnPokerButton()
{
	aux = head;
	Player* player;
	while (aux != nullptr) {
		player = aux->getPlayer();
		player->returnPokerButton();
		aux = aux->getNext();
	}
}

void List::shiftLeftHead()
{
	aux = head;
	Node* prevHead = head;

	while (aux->getNext() != nullptr) {
		aux = aux->getNext();
	}

	aux->setNext(head);
	head = head->getNext();
	prevHead->setNext(nullptr);
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

int List::getTotalPlayer()
{
	aux = head;
	int count = 0;

	while (aux != nullptr)
	{
		aux = aux->getNext();
		count++;
	}

	return count;
}

void List::dealPokerButtonsToPlayers(PokerButton** pokerButtons)
{
	int i, count = 0;
	aux = head;

	for (i = 0; i < 2; i++) {

		while (aux != nullptr) {

			if (count < 3) {
				aux->getPlayer()->takePokerButton(pokerButtons[count]);
				count++;
			}
			else {
				shiftLeftHead();
				return;
			}	

			aux = aux->getNext();
		}

		aux = head;
	}
	

	return;
}

int List::findPlayerNextToBigBlind(PokerButton* button)
{
	aux = head;
	int position = 1;

	while (aux != nullptr && !aux->getPlayer()->haveIPokerButton(button)) {
		aux = aux->getNext();
		position++;
	}

	if (aux->getNext() == nullptr) {
		aux = head;
		position = 1;
	}

	else {
		aux = aux->getNext();
		position++;
	}

	return position;
}

Player* List::findWinner(Card** communityDeck, int& numPlayersInThisRound)
{
	if (numPlayersInThisRound == 1) {
		aux = head;

		while (aux->getPlayer()->isInGame() != true) {
			aux = aux->getNext();
		}

		return aux->getPlayer();
	}

	aux = head;
	Player* winner = aux->getPlayer(); //nullptr

	int pointsOfActualPlayer = 0;
	int pointOfWinnerPlayer = 0;

	while (aux != nullptr) {
		if (aux->getPlayer()->isInGame()) {
			pointsOfActualPlayer = aux->getPlayer()->getPointOfHand(communityDeck);

			if (pointsOfActualPlayer > pointOfWinnerPlayer) {
				pointOfWinnerPlayer = pointsOfActualPlayer;
				winner = aux->getPlayer();
			}

		}
		std::cout << pointsOfActualPlayer << '\n';
		aux = aux->getNext();
	}
	std::cout << "ganador: " << winner->getId() << '\n';
	system("pause");
	return winner;
}


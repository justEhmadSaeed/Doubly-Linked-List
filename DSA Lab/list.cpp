#include <iostream>
#include "node.cpp"
using namespace std;
class list {
	Node* headNode;
	Node* currentNode;
	int size;
public:
	list() {	// default Constructor

		headNode = 0;
		currentNode = 0;
		size = 0;
	}

	void insert(int n) {
		// to insert a node in list class after current node

		if (currentNode != 0)	// case if list is not empty
		{
			if (currentNode->getNext() == 0) {	// if current node is at the end of list

				Node* newNode = new Node();
				currentNode->setNext(newNode);
				newNode->setPrev(currentNode);
				currentNode = newNode;
				currentNode->setValue(n);
				currentNode->setNext(0);
			}
			else
			{	//if current node is somewhere in the middle of list

				Node* newNode = new Node();
				newNode->setNext(currentNode->getNext());
				currentNode->setNext(newNode);
				newNode->setPrev(currentNode);
				currentNode = newNode;
				currentNode->setValue(n);
			}
		}
		else
		{	// if the list is empty

			Node* newNode = new Node();
			headNode = newNode;
			currentNode = headNode;
			newNode->setPrev(0);
			currentNode->setValue(n);
			currentNode->setNext(0);
		}
		size++;	// size increment

	}

	void insertAtBegin(int num) {
		// to insert the node at the beginning
		start();
		Node* newNode = new Node();
		newNode->setNext(currentNode);
		currentNode = newNode;
		currentNode->setValue(num);
		headNode = currentNode;
		newNode->setPrev(0);
		size++;
	}
	void insertAtEnd(int num) {
		// To insert a node at the end of list
		start();
		for (int i = 0; i < size - 1; i++)
		{
			forward();
		}
		Node* newNode = new Node();
		currentNode->setNext(newNode);
		currentNode = newNode;
		currentNode->setValue(num);
		currentNode->setNext(0);
		size++;
	}
	// To delete the node, possessing specific value
	void deleteByValue(int val) {

		start();
		for (int i = 0; i < size; i++) {
			cout << "check0\n";
			if (currentNode->getValue() == val) {	// if programs matches argument with nodes' values
				if (currentNode->getNext() != 0)	// if target node is not at the end 
					if (currentNode == headNode)	// if target node is head node
					{
						cout << "check1\n";

						Node* nn = new Node();
						nn = currentNode->getNext();
						delete currentNode;
						currentNode = nn;
						headNode = currentNode;
						currentNode->setPrev(0);
					}

					else {
						// if target node is somewhere in the middle of list
						cout << "check2\n";
						Node* nn = currentNode->getPrev();
						(currentNode->getPrev())->setNext(currentNode->getNext());
						(currentNode->getNext())->setPrev(currentNode->getPrev());
						delete currentNode;
						currentNode = nn;
					}
				else {

					if (size == 1) {	// target could be at the last and the least
						cout << "check3\n";
						headNode = NULL;
						delete currentNode;
						currentNode = headNode;
					}
					else {	// if target node is at last but other nodes are also present
						cout << "check4\n";

						Node* nn = new Node();
						nn->setPrev(currentNode->getPrev());
						delete currentNode;
						currentNode = nn;
					}
					currentNode->setNext(0);
				}
				size--;
				break;	
			}
			forward();	// to make it move further a step in linked list
		}
	}
	void start() {
		// To move the current node to head node i.e at the start of the list
		currentNode = headNode;
	}
	// To move forward in the linked list
	void forward() {

		if (currentNode->getNext() != 0) {
			currentNode = currentNode->getNext();
		}
	}
	// To move back in the linked list
	void back() {
		if (currentNode->getPrev() != 0)
			currentNode = currentNode->getPrev();
	}
	// To get the size of Linked List
	int getSize() {
		return size;
	}

	// To get the value of Current Node
	int get() {
		return	currentNode->getValue();
	}

	// To display All the values of Nodes
	void display() {

		if (headNode == NULL)
			cout << " List is empty/n";
		else {

			start();
			for (int i = 0; i < size; i++)
			{
				cout << get() << endl;
				if (i < size - 1)
					forward();
			}
		}
	}
};
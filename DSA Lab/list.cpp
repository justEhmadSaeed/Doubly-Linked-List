#include <iostream>
#include "node.cpp"
using namespace std;
class list {
	Node* head;
	Node* current;
	int size;
public:
	list() {	// default Constructor

		head = 0;
		current = 0;
		size = 0;
	}

	void insert(int n) {
		// to insert a node in list class after current node
		Node* newnode = new Node();
		if (size == 0) {
			head = newnode;
		}
		else
		{
			if (current->getNext() != 0) {
				newnode->setNext(current->getNext());
				(newnode->getNext())->setPrev(newnode);
			}
			current->setNext(newnode);
			newnode->setPrev(current);
		}
		current = newnode;
		current->setValue(n);
		size++;
	}

	void insertAtBegin(int num) {
		// to insert the node at the beginning
		start();
		Node* newNode = new Node();
		newNode->setNext(current);
		current = newNode;
		current->setValue(num);
		head = current;
		size++;
	}
	void insertAtEnd(int num) {
		// To insert a node at the end of list
		start();
		for (int i = 1; i < size; i++)
		{
			forward();
		}
		insert(num);
	}
	// To delete the node, possessing specific value
	void deleteByValue(int val) {

		start();
		for (int i = 0; i < size; i++) {
			if (current->getValue() == val) {	// if programs matches argument with nodes' values
				if (current->getNext() != 0)	// if target node is not at the end 
					if (current == head)		// if target node is head node
					{

						Node* nn = new Node();
						nn = current->getNext();
						delete current;
						current = nn;
						head = current;
						current->setPrev(0);
					}

					else {
						// if target node is somewhere in the middle of list
						Node* nn = current->getPrev();
						(current->getPrev())->setNext(current->getNext());
						(current->getNext())->setPrev(current->getPrev());
						delete current;
						current = nn;
					}
				else {

					if (size == 1) {	// target could be at the last and the least
						head = NULL;
						delete current;
						current = head;
					}
					else {	// if target node is at last but other nodes are also present

						Node* nn = new Node();
						nn->setPrev(current->getPrev());
						delete current;
						current = nn;
					}
					current->setNext(0);
				}
				size--;
				break;
			}
			forward();	// to make it move further a step in linked list
		}
	}
	void start() {
		// To move the current node to head node i.e at the start of the list
		current = head;
	}
	// To move forward in the linked list
	void forward() {

		if (current->getNext() != 0) {
			current = current->getNext();
		}
	}
	// To move back in the linked list
	void back() {
		if (current->getPrev() != 0)
			current = current->getPrev();
	}
	// To get the size of Linked List
	int getSize() {
		return size;
	}

	// To get the value of Current Node
	int get() {
		return	current->getValue();
	}

	// To display All the values of Nodes
	void display() {

		if (head == NULL)
			cout << " List is empty/n";
		else {

			start();
			cout << "\nList Nodes' Values:\n";
			for (int i = 0; i < size; i++)
			{
				cout << get() << endl;
				if (i < size - 1)
					forward();
			}
		}
	}
};
#include "linkedlist.h"

int linkedlist::count() //i know not needed, but i put it in 
{
	int counter = 0;
	Node* iterator = head;

	while (iterator != NULL)
	{
		iterator = iterator->next;
		counter++;

	}
	return counter;


}

void linkedlist::dispalyLinkedList()
{

	Node* iterator = head;
	while (iterator != NULL)
	{
		//(*iterator).name; its dereference pointer and access public thing
		cout << iterator->number << endl;
		iterator = iterator->next;                //this piece i left out
	}
}

void linkedlist::insertAtBeginning(int number)
{
	Node* newNode = new Node(number);
	newNode->next = head;
	head = newNode;
}

void linkedlist::insertAtEnd(int number)
{
	Node* newNode = new Node(number);
	Node* iterator = head;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = newNode;
}

void linkedlist::deleteFromBeginning(int number)
{
	if (head == NULL)
	{
		return;
	}

	Node* iterator = head;

	head = head->next;

	delete iterator;
}

void linkedlist::deleteFromEnd(int number)
{

	if (head == NULL)
		return;
	Node* iterator = head;
	Node* previous = head;
	while (iterator->next != NULL)
	{
		previous = iterator;
		iterator = iterator->next;

	}
	previous->next = NULL;
	delete iterator;
}

#include "linkedlist.h"

int linkedlist::count()
{
	int counter = 0;
	Node* iterator = head;

	while (iterator!= NULL)
	{
		iterator = iterator->next;
		counter++;

	}
	return counter;

	return 0;
}

void linkedlist::dispalyLinkedList()
{

	Node* iterator = head;
	while (iterator != NULL)
	{
		//(*iterator).name; its dereference pointer and access public thing
		cout << iterator->number<< endl;
		iterator = iterator->next;                //this piece i left out
	}
}

void linkedlist::insertAtBeginning(int number)
{
}

void linkedlist::insertAtEnd(int number)
{
}

void linkedlist::deleteFromBeginning(int number)
{
}

void linkedlist::deleteFromEnd(int number)
{
}

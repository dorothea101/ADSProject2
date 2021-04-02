#pragma once
#include <iostream>
#include <stdlib.h>
#include "Node.h"


using namespace std;
class linkedlist
{
public:
	Node* head = NULL;

	int count();
	void dispalyLinkedList();

	void insertAtBeginning(int number);
	void insertAtEnd(int number);
	void deleteFromBeginning(int number);
	void deleteFromEnd(int number);


}

#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <vector>
#include "linkedlist.h"

using namespace std;

void main() {
	linkedlist listBeggining;
	linkedlist listEnd;

	ifstream readFile;
	readFile.open("input-a1q2.txt");
	int numberOfRandomNumber;
	readFile >> numberOfRandomNumber;


	std::chrono::steady_clock::time_point insertBbegin = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfRandomNumber; i + 1)
	{
		listBeggining.insertAtBeginning(rand());
	}
	std::chrono::steady_clock::time_point insertBend = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point insertEbegin = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfRandomNumber; i + 1)
	{
		listEnd.insertAtEnd(rand());
	}
	std::chrono::steady_clock::time_point insertEend = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point deleteBbegin = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfRandomNumber; i + 1)
	{
		listBeggining.deleteFromBeginning(rand());
	}
	std::chrono::steady_clock::time_point deleteBend = std::chrono::steady_clock::now();


	std::chrono::steady_clock::time_point deleteEbegin = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfRandomNumber; i + 1)
	{
		listEnd.deleteFromEnd(rand());
	}
	std::chrono::steady_clock::time_point deleteEend = std::chrono::steady_clock::now();

	ofstream  writeFile;
	writeFile.open("lol.txt");
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(insertBend - insertBbegin).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(insertEend - insertEbegin).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(deleteBend - deleteBbegin).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(deleteEend - deleteEbegin).count() << endl;













	system("pause");
}
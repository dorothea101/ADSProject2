#include <iostream>
#include <string>
#include <chrono> 
#include <fstream> 
#include <windows.h> 
#include <vector>

using namespace std;

void displayArray(int arr[], int arraySize)
{
	for (int i = 0; i <= arraySize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mySwap(int arr[], int i, int j) {

	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int arr[], int arraySize, int order)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i <= arraySize - 1 - 1; i++)
		{
			if (order == 1)
			{
				if (arr[i] < arr[i + 1])
				{
					mySwap(arr, i, i + 1);
					sorted = false;
				}
			}
			if (order == 0)
			{
				if (arr[i] > arr[i + 1])
				{
					mySwap(arr, i, i + 1);
					sorted = false;
				}
			}
		}

	}
}

int partition(int a[], int low, int high, int order)
{
	int pivot = a[low];
	int i = low;
	int j = high;
	if (order == 0)
	{
		while (i < j)
		{
			do {

				i++;

			} while (a[i] <= pivot);

			do {
				j--;
			} while (a[j] > pivot);

			if (i < j)
				swap(a[i], a[j]);
		}
	}
	if (order == 1)
	{
		{
			while (i < j)
			{
				do {

					i++;

				} while (a[i] >= pivot);

				do {
					j--;
				} while (a[j] < pivot);

				if (i < j)
					swap(a[i], a[j]);
			}
		}
	}
	swap(a[low], a[j]);
	return j;
}

void quickSort(int a[], int low, int high, int order)
{
	if (low < high)
	{
		int partitionIndex = partition(a, low, high, order);
		quickSort(a, low, partitionIndex, order);
		quickSort(a, partitionIndex + 1, high, order);
	}
}

void main()
{
	ifstream readFile;
	ofstream  writeFile;
	writeFile.open("output-a1q1.txt");
	readFile.open("input-a1q1.txt");
	int order;
	readFile >> order;
	int complexity;
	readFile >> complexity;
	int sizeOfArray;
	readFile >> sizeOfArray;


	
	if (order != 0 && order != 1)
	{
		cout << "Error encounetered! should be a 0 or 1 in line 1" << endl;
		return;
	}
	if (complexity != 0 && complexity != 1)
	{
		cout << "Error encounetered! should be a 0 or 1 in line 2" << endl;
		return;
	}
	if (sizeOfArray < 0)
	{
		cout << "line 3 cannot be a negative numbser!" << endl;
		return;
	}

	int* arr = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		readFile >> arr[i];
		if (i < (sizeOfArray - 1))
			if (readFile.eof())
			{
				cout << "There are not the right quantity of numbers in line 4 !" << endl;
				return;
			}
	}

	if (complexity == 0)
	{
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		bubbleSort(arr, sizeOfArray, order);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		writeFile << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
		for (int i = 0; i < sizeOfArray; i++)
		{
			writeFile << arr[i] << " ";
		}
	}
	else if(complexity ==1)
	{
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		quickSort(arr, 0, sizeOfArray, order);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		writeFile << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
		for (int i = 0; i < sizeOfArray; i++)
		{
			writeFile << arr[i] << " " ;
		}
	}
	system("pause");
}
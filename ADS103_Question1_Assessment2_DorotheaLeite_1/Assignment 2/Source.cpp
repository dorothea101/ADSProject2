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
	readFile.open("input-a1q1.txt");
	int order;
	readFile >> order;
	int complexity;
	readFile >> complexity;
	int sizeOfArray;
	readFile >> sizeOfArray;


	int* arr = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		readFile >> arr[i];
	}
	if (order != 0 || order != 1)
	{
		cout << "Error encounetered! should be a 0 or 1 in line 1" << endl;
		return;
	}
	if (complexity != 0 || complexity != 1)
	{
		cout << "Error encounetered! should be a 0 or 1 in line 2" << endl;
		return;
	}

	if (complexity == 0)
	{
		bubbleSort(arr, sizeOfArray, order);
	}
	else if(complexity ==1)
	{ 
		quickSort(arr, 0, sizeOfArray, order);
	}


	//quickSort(arr, 0, sizeOfArray, order);
	//bubbleSort(arr, sizeOfArray, order);
	//displayArray(arr, sizeOfArray);





	system("pause");
}
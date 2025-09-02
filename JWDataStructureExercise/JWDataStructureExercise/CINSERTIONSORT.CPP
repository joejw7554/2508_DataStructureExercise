#include "CInsertionSort.h"

void CInsertionSort::DoInserstionSort(int Arr[], int size)
{

	for (int i = 1; i < size; i++)
	{
		int currentNum = Arr[i];
		int j = i - 1;

		while (j >= 0 && Arr[j] > currentNum)
		{
			Arr[j + 1] = Arr[j];
			j--;
		}

		Arr[j+1] = currentNum;


	}

	

	for (int i = 0; i < size; i++)
	{
		cout << Arr[i] << (i < size - 1 ? " " : "\n");
	}

}

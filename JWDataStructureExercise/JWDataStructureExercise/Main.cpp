#include "Array.h"
#include "CBubbleSort.h"
#include "CInsertionSort.h"
#include <iostream>

using namespace std;


void ArrImplementation()
{
	JWArray<int> myArr(5);

	myArr.Pushback(10);
	myArr.Pushback(30);
	myArr.Pushback(40);

	myArr.Insert(1, 20);

	myArr.Find(30);
	myArr.Display();

	myArr.Clear();
}

int main()
{
	//ArrImplementation();

	int Arr[] = { 13,1,10,8,3,2,6 };
	int size = sizeof(Arr) / sizeof(Arr[0]);

	
	CInsertionSort::DoInserstionSort(Arr,size);

	return 0;
}


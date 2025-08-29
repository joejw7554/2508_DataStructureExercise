#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
	JWArray<int> myArr(5);

	myArr.Pushback(10);
	myArr.Pushback(30);
	myArr.Pushback(40);

	myArr.Insert(1, 20);

	myArr.Find(30);
	myArr.Display();

	myArr.Clear();



	return 0;
}
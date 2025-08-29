#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
	JWArray<int> myArr(5);

	myArr.Pushback(10);
	myArr.Pushback(20);
	myArr.Pushback(30);
	myArr.Pushback(40);
	myArr.Pushback(50);

	myArr.Display();

	cout << myArr[0] << endl;


	return 0;
}
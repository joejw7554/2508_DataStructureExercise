#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class JWArray
{
	int MaxSize;
	int CurrentIndex = 0;
	T* ArrayPtr;

public:
	JWArray(int InSize) : MaxSize(InSize)
	{
		ArrayPtr = new T[MaxSize];
	}

	~JWArray()
	{
		if (ArrayPtr != nullptr)
		{
			delete[] ArrayPtr;
			ArrayPtr = nullptr;
		}
	}

	void Pushback(const T& Value)
	{	
		if (CurrentIndex < MaxSize)
		{
			ArrayPtr[CurrentIndex] = Value;
			CurrentIndex++; // �ε��� ���� �߰�
		}
		else
		{
			cout << "Array is Full" << endl;
		}
	}

	void Display()
	{
		for (int i = 0; i < CurrentIndex; i++) // CurrentIndex������ ���
		{
			cout << ArrayPtr[i] << endl;
		}
	}

	void Insert(int index, const T& Value)
	{
		if (Current >= MaxSize)
		{
			throw out_of_range("Array is Full. Cannot Insert!");
		}

		if (index >= MaxSize || index < 0)
		{
			throw out_of_range("InValid Index");
		}

		//�ݺ��� ����: index���� ��: Max����?
		

		//


	}





public:
	T& operator[](const int& InIndex)
	{
		if (InIndex < 0 || InIndex >= MaxSize)
		{
			throw out_of_range("Index out of range");
		}
		return ArrayPtr[InIndex];
	}

	const T& operator[](int InIndex) const
	{
		if (InIndex < 0 || InIndex >= MaxSize)
		{
			throw out_of_range("Index out of range");
		}
		return ArrayPtr[InIndex];
	}
};
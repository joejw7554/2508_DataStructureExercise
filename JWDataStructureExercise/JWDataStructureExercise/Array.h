#include <memory>
#include <iostream>
#include <stdexcept>

#define CHECKINDEX(x) { if ((x) < 0 || (x) >= CurrentIndex) throw out_of_range("Invalid Index"); }

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
			CurrentIndex++;
		}
		else
		{
			cout << "Array is Full" << endl;
		}
	}

	void Display()
	{
		for (int i = 0; i < CurrentIndex; i++)
		{
			cout << ArrayPtr[i] << endl;
		}
	}

	void Insert(int Index, const T& Value)
	{
		if (CurrentIndex >= MaxSize)
		{
			throw out_of_range("Array is Full. Cannot Insert!");
		}

		if (Index < 0 || Index > CurrentIndex) // Insert는 CurrentIndex까지 허용
		{
			throw out_of_range("Invalid Index");
		}

		// 올바른 범위: CurrentIndex부터 Index까지
		for (int i = CurrentIndex; i > Index; i--)
		{
			ArrayPtr[i] = ArrayPtr[i - 1];
		}

		ArrayPtr[Index] = Value;
		CurrentIndex++;
	}

	void Remove(int Index)
	{
		CHECKINDEX(Index); // 현재 유효한 요소만 삭제 가능

		// 삭제할 요소 이후의 모든 요소를 왼쪽으로 한 칸씩 이동
		for (int i = Index; i < CurrentIndex - 1; i++)
		{
			ArrayPtr[i] = ArrayPtr[i + 1];
		}

		CurrentIndex--; // 배열 크기 감소
		cout << "Element at index " << Index << " removed successfully." << endl;
	}

	void Find(int InValue)
	{
		for (int i = 0; i < GetSize(); i++)
		{
			if (ArrayPtr[i] == InValue)
			{
				cout << InValue << " is located at " << i << endl;
				return;
			}
		}

		cout << "There is no such element:" <<InValue << endl;

	}


	void Clear()
	{
		cout << "Current elements before clear:" << endl;
		for (int i = 0; i < CurrentIndex; i++)
		{
			cout << ArrayPtr[i] << endl;
		}
		
		CurrentIndex = 0;

		cout << "Array cleared" << endl;
	}

public:
	T& operator[](const int& InIndex)
	{
		CHECKINDEX(InIndex);
		return ArrayPtr[InIndex];
	}

	const T& operator[](int InIndex) const
	{
		if (InIndex < 0 || InIndex >= CurrentIndex)
		{
			throw out_of_range("Index out of range");
		}
		return ArrayPtr[InIndex];
	}

	// 유틸리티 함수들
	int GetSize() const { return CurrentIndex; }
	int GetCapacity() const { return MaxSize; }
	bool IsEmpty() const { return CurrentIndex == 0; }
};
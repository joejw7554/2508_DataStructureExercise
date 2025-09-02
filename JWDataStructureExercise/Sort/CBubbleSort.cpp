#include "CBubbleSort.h"
#include "Common.h"

void CBubbleSort::DoBubbleSort(int* Arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; ++j)
        {
            if (Arr[j] > Arr[j + 1])
            {
                std::swap(Arr[j], Arr[j + 1]);  // �� ����� ��ȯ
                swapped = true;
            }
        }

        if (!swapped) break;  // ���� ���� ����ȭ
    }

    cout << "Bubble Sorted: ";
    for (int i = 0; i < size; ++i)
    {
        cout << Arr[i] << (i < size - 1 ? " " : "\n");
    }
}



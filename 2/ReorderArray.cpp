#include "ReorderArray.h"

ReorderArray::ReorderArray() : DynamicArray() {}
ReorderArray::ReorderArray(int n) : DynamicArray(n) {}

void ReorderArray::calc() const {
    if (size == 0) return;

    int* temp = new int[size];
    int index = 0;

    for (int i = 0; i < size; i++)
        if (data[i] == 0)
            temp[index++] = data[i];

    for (int i = 0; i < size; i++)
        if (data[i] < 0)
            temp[index++] = data[i];

    for (int i = 0; i < size; i++)
        if (data[i] > 0)
            temp[index++] = data[i];

    std::cout << "Reordered array: ";
    for (int i = 0; i < size; i++)
        std::cout << temp[i] << " ";
    std::cout << "\n";

    delete[] temp;
}

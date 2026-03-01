#include "DynamicArray.h"
#include <cstdlib>
#include <ctime>

DynamicArray::DynamicArray() : size(10) {
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = rand() % 201 - 100;
}

DynamicArray::DynamicArray(int n) {
    if (n > 0) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = rand() % 201 - 100;
    } else {
        size = 0;
        data = nullptr;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    } else {
        data = nullptr;
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
    }
    return *this;
}

void DynamicArray::printAuthor() const {
    std::cout << "Author: Surname I.O., group, variant 33\n";
}

void DynamicArray::print() const {
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

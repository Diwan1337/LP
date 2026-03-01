#include "DynamicArray.h"
#include <cstdlib>
#include <ctime>

static bool seeded = false;

DynamicArray::DynamicArray() : DynamicArray(10) {}

DynamicArray::DynamicArray(int n) {
    if (n <= 0) {
        size = 0;
        data = nullptr;
        return;
    }

    size = n;
    data = new int[size];

    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }

    for (int i = 0; i < size; i++) {
        data[i] = std::rand() % 201 - 100;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;

    if (size == 0) {
        data = nullptr;
        return;
    }

    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::printAuthor() const {
    std::cout << "Автор программы: Фамилия Имя" << std::endl;
}

void DynamicArray::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;

    if (size == 0) {
        data = nullptr;
        return *this;
    }

    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

// Постфиксный --
DynamicArray DynamicArray::operator--(int) {
    DynamicArray temp(*this);

    if (size == 0)
        return temp;

    for (int i = 0; i < size; i++) {
        if (data[i] > 0)
            data[i]--;
    }

    return temp;
}

// Поэлементное вычитание числа из положительных элементов
DynamicArray operator-(const DynamicArray& arr, int value) {
    DynamicArray result(arr);

    if (result.size == 0)
        return result;

    for (int i = 0; i < result.size; i++) {
        if (result.data[i] > 0)
            result.data[i] -= value;
    }

    return result;
}

// Сравнение по максимальному значению
bool operator>(const DynamicArray& a, const DynamicArray& b) {
    if (a.size == 0 && b.size == 0)
        return false;

    if (a.size == 0)
        return false;

    if (b.size == 0)
        return true;

    int maxA = a.data[0];
    int maxB = b.data[0];

    for (int i = 1; i < a.size; i++)
        if (a.data[i] > maxA)
            maxA = a.data[i];

    for (int i = 1; i < b.size; i++)
        if (b.data[i] > maxB)
            maxB = b.data[i];

    return maxA > maxB;
}

// Запись в файл
void saveToFile(const DynamicArray& arr, const std::string& filename) {
    if (arr.size == 0)
        return;

    std::ofstream file(filename);

    if (!file.is_open())
        return;

    for (int i = 0; i < arr.size; i++)
        file << arr.data[i] << " ";

    file.close();
}

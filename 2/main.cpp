#include <windows.h>
#include <ctime>
#include <iostream>

#include "MinMaxArray.h"
#include "BetweenSumArray.h"
#include "ReorderArray.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));

    // массив указателей на базовый класс
    DynamicArray* arr[4];

    // 1. Конструктор по умолчанию
    arr[0] = new MinMaxArray();

    // 2. Конструктор с параметром
    arr[1] = new BetweenSumArray(15);

    // 3. Создание временного объекта и копирование
    MinMaxArray temp(10);
    arr[2] = new MinMaxArray(temp);

    // 4. Еще один конструктор с параметром
    arr[3] = new ReorderArray(20);

    // Демонстрация полиморфизма
    for (int i = 0; i < 4; i++) {
        arr[i]->printAuthor();
        arr[i]->print();
        arr[i]->calc();
        std::cout << "-----------------------------\n";
    }

    // Очистка памяти
    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    return 0;
}

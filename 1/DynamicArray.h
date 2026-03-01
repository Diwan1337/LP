#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <fstream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    // Конструкторы
    DynamicArray();
    DynamicArray(int n);
    DynamicArray(const DynamicArray& other);

    // Деструктор
    ~DynamicArray();

    // Обязательные функции
    void printAuthor() const;
    void print() const;

    // Перегруженный оператор присваивания
    DynamicArray& operator=(const DynamicArray& other);

    // Компонентная операция (постфиксный --)
    DynamicArray operator--(int);

    // Дружественная операция (поэлементное вычитание числа)
    friend DynamicArray operator-(const DynamicArray& arr, int value);

    // Глобальная операция сравнения по максимуму
    friend bool operator>(const DynamicArray& a, const DynamicArray& b);

    // Глобальная функция записи в файл
    friend void saveToFile(const DynamicArray& arr, const std::string& filename);
};

#endif

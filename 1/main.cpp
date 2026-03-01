#include "DynamicArray.h"

int main() {

    DynamicArray a(5);
    DynamicArray b(3);
    DynamicArray empty(0);
    DynamicArray one(1);

    std::cout << "a: ";
    a.print();

    std::cout << "b: ";
    b.print();

    std::cout << "empty: ";
    empty.print();

    std::cout << "one: ";
    one.print();

    // тест --
    a--;
    std::cout << "a после a--: ";
    a.print();

    // тест -
    DynamicArray c = a - 10;
    std::cout << "c = a - 10: ";
    c.print();

    // сравнение
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a > empty: " << (a > empty) << std::endl;
    std::cout << "empty > a: " << (empty > a) << std::endl;

    // присваивание
    b = a;
    std::cout << "b после b = a: ";
    b.print();

    // самоприсваивание
    a = a;

    saveToFile(a, "output.txt");

    return 0;
}

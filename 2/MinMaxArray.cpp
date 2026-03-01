#include "MinMaxArray.h"
#include <cmath>

MinMaxArray::MinMaxArray() : DynamicArray() {}
MinMaxArray::MinMaxArray(int n) : DynamicArray(n) {}

void MinMaxArray::calc() const {
    if (size == 0) return;

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (std::abs(data[i]) < std::abs(data[minIndex]))
            minIndex = i;
        if (std::abs(data[i]) > std::abs(data[maxIndex]))
            maxIndex = i;
    }

    std::cout << "Min by absolute value: index "
              << minIndex << ", value "
              << data[minIndex] << "\n";

    std::cout << "Max by absolute value: index "
              << maxIndex << ", value "
              << data[maxIndex] << "\n";
}

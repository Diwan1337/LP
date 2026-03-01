#include "BetweenSumArray.h"
#include <cmath>

BetweenSumArray::BetweenSumArray() : DynamicArray() {}
BetweenSumArray::BetweenSumArray(int n) : DynamicArray(n) {}

void BetweenSumArray::calc() const {
    if (size == 0) return;

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (std::abs(data[i]) < std::abs(data[minIndex]))
            minIndex = i;
        if (std::abs(data[i]) > std::abs(data[maxIndex]))
            maxIndex = i;
    }

    if (minIndex > maxIndex)
        std::swap(minIndex, maxIndex);

    int sum = 0;
    for (int i = minIndex + 1; i < maxIndex; i++)
        sum += data[i];

    std::cout << "Sum between them: " << sum << "\n";
}

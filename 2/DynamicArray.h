#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray {
protected:
    int* data;
    int size;

public:
    DynamicArray();
    DynamicArray(int n);
    DynamicArray(const DynamicArray& other);
    virtual ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    void printAuthor() const;
    void print() const;

    virtual void calc() const = 0;
};

#endif

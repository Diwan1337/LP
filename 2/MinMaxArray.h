#ifndef MINMAXARRAY_H
#define MINMAXARRAY_H

#include "DynamicArray.h"

class MinMaxArray : public DynamicArray {
public:
    MinMaxArray();
    MinMaxArray(int n);
    void calc() const override;
};

#endif

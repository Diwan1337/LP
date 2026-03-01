#ifndef BETWEENSUMARRAY_H
#define BETWEENSUMARRAY_H

#include "DynamicArray.h"

class BetweenSumArray : public DynamicArray {
public:
    BetweenSumArray();
    BetweenSumArray(int n);
    void calc() const override;
};

#endif

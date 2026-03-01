#ifndef REORDERARRAY_H
#define REORDERARRAY_H

#include "DynamicArray.h"

class ReorderArray : public DynamicArray {
public:
    ReorderArray();
    ReorderArray(int n);
    void calc() const override;
};

#endif

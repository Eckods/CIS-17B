// Derived.h
#include "Base.h"

#ifndef DERIVED_H
#define DERIVED_H

class Derived : public Base{
public:
    Derived(int rows, int cols) : Base(rows, cols){}
    void toPrint(int** numbArray, int rows, int cols)const;
};
#endif

// Base.h
#include "Abstract.h"

#ifndef BASE_H
#define BASE_H

class Base : public Abstract{
protected:
    int nRows;
    int nCols;
    int **array;
public:
    Base(int, int);
    ~Base();
    virtual int** fill_array(int, int);
    char* toString();
};
#endif

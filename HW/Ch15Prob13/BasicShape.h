#include <iostream>
using namespace std;

#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape{
protected:
    float area;
public:
    float getArea()const
    { return area; }
    virtual void calcArea() = 0;
};
#endif // BASICSHAPE_H

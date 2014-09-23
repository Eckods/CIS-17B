#include "BasicShape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public BasicShape{
private:
   int width;
   int length;
public:
    Rectangle(int width, int length){
        this->length = length;
        this->width = width;
        calcArea();
    }
    int getWidth()const
    { return width; }
    int getLength()const
    { return length; }
    virtual void calcArea()
    { area = length * width; }
};
#endif // RECTANGLE_H

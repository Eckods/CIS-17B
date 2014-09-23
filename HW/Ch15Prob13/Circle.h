#include "BasicShape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public BasicShape{
private:
    int centerX;
    int centerY;
    float radius;
public:
    Circle(int centerX, int centerY, float radius){
        this->centerX = centerX;
        this->centerY = centerY;
        this->radius = radius;
        calcArea();
    }
    int getCenterY()const
    { return centerY; }
    int getCenterX()const
    { return centerX; }
    virtual void calcArea()
    { area = 3.14159 * radius * radius; }
};
#endif // CIRCLE_H

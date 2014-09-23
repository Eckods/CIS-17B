#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
private:
   int hours;
   float days;
public:
    NumDays(int);
    ~NumDays();
    int getHours()const;
    float getDays()const;
    void setHours(int);
    void setDays(float);
    void displayDays()const;
    int operator + (NumDays&);
    int operator - (NumDays&);
    NumDays& operator++();
    NumDays& operator--();
    NumDays operator++(int);
    NumDays operator--(int);
};
#endif // NUMDAYS_H

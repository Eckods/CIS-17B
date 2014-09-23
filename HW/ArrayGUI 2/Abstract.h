// Abstract.h
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sstream>
#include <QApplication>
#include <QLabel>

using namespace std;

#ifndef ABSTRACT_H
#define ABSTRACT_H

class Abstract{
public:
    virtual int** fill_array(int, int)= 0;
};
#endif

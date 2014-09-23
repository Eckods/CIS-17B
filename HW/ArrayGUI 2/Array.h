// Array.h
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sstream>
#include <QApplication>
#include <QLabel>

using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

class Array{
public:
    virtual int fill_array()= 0;
};

#endif

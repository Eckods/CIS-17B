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
private:
    int nRows;
    int nCols;
    int** array;
public:
    Array(int, int);
    ~Array();
    char* toString();
};

#endif

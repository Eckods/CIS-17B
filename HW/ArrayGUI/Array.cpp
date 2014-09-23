// Array.cpp
#include "Array.h"

Array::Array(int rows, int cols)
{
    nRows = rows;
    nCols = cols;
    array = new int*[nRows];

    // Allocate the array
    for (int i = 0; i < nRows; i++){
        array[i] = new int[cols];
    }

    // Fill the array
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            array[i][j] = 10 + rand() % (99 - 10);
        }
    }
}

Array::~Array()
{
    for (int i = 0; i < nRows; i++){
        delete [] array[i];
    }
    delete [] array;
}

char* Array::toString(){
    stringstream sso;

    // Convert int to string
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            sso << array[i][j] << "  ";
        }
        sso << endl;
    }
    string result = sso.str();

    // Convert string to char
    char* numbers = new char[result.length()];
    strcpy(numbers, result.c_str());
    return numbers;
}



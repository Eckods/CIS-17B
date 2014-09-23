// Base.cpp
#include "Base.h"

Base::Base(int rows, int cols){
    nRows = rows;
    nCols = cols;
}

Base::~Base(){
    for (int i = 0; i < nRows; i++){
        delete [] array[i];
    }
    delete [] array;
}

int** Base::fill_array(int rows, int cols){
    array = new int*[rows];
    // Allocate the array
    for (int i = 0; i < rows; i++){
        array[i] = new int[cols];
    }
    // Fill the array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            array[i][j] = 10 + rand() % (99 - 10);
        }
    }
    return array;
}
char* Base::toString(){
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

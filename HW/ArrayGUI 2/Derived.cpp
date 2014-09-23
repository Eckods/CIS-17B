// Derived.cpp
#include "Derived.h"

void Derived::toPrint(int** numbArray, int rows, int cols)const{
    cout << "The array contains the following numbers:" << endl;

    // Display the array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << numbArray[i][j] << "  ";
        }
        cout << endl;
    }
}





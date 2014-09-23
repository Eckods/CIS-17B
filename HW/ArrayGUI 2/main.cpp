/* Steve Sanchez
 * September 17th, 2014
 * Purpose: Polymorphism and an array with GUI
 */
// main.cpp
#include "Derived.h"

//Execution Begins Here
int main (int argc, char **argv){
    QApplication app(argc, argv);
    int rows = 5;
    int cols = 6;
    srand(time(NULL));
    char* numb;
    int** numbArray;

    Derived randomArray(rows, cols);
    numbArray = randomArray.fill_array(rows, cols);
    numb = randomArray.toString();
    randomArray.toPrint(numbArray, rows, cols);

    // Display the label
    QLabel *label = new QLabel(numb);
    label->show();
    return app.exec();
}


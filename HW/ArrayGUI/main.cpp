/* Steve Sanchez
 * September 10th, 2014
 * Purpose: An array with GUI
 */
// main.cpp
// Qt Libraries
#include "Array.h"

//Execution Begins Here
int main (int argc, char **argv){
    QApplication app(argc, argv);
    int rows = 5;
    int cols = 6;
    srand(time(NULL));
    char* numbers;

    Array randomArray(rows, cols);
    numbers = randomArray.toString();

    QLabel *label = new QLabel(numbers);
    label->show();
    return app.exec();
}


#include "MainWindow.h"
#include "GameManager.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}

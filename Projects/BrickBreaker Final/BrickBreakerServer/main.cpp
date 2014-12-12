#include <QApplication>
#include <QPushButton>
#include "BrickBreakerServer.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    BrickBreakerServer server;
    if (!server.listen(QHostAddress::Any, 6178)) {
        qDebug() << "Failed to bind to port";
        return 0;
    }

    // Creates an object of QPushButton
    QPushButton quitButton(QObject::tr("&Quit"));
    QObject::connect(&quitButton, SIGNAL(clicked()),&a, SLOT(quit()));
    quitButton.setMinimumSize(280, 60);
    quitButton.show();

    // Sets the window title
    quitButton.setWindowTitle(QObject::tr("Brick Breaker Server"));

    return a.exec();
}


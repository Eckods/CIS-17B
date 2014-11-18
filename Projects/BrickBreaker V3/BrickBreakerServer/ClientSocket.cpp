#include <QtNetwork>
#include <QtGui>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "ClientSocket.h"
using namespace std;

ClientSocket::ClientSocket(QObject *parent)
    : QTcpSocket(parent){
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));

    nextBlockSize = 0;
}

ClientSocket::~ClientSocket(){}

void ClientSocket::readClient(){
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_3);

    if (nextBlockSize == 0) {
        if (bytesAvailable() < sizeof(quint16))
            return;
        in >> nextBlockSize;
    }

    if (bytesAvailable() < nextBlockSize)
        return;

    srand(time(NULL));

    // Sets up a variable to hold numerical scores
    quint16 score[NumRows] = {0};

    // Creates a sorted list of random numbers in the 1200-1500 range
    priority_queue <int> sortedScores;
    for (int j = 0; j < NumRows; ++j){
        sortedScores.push(1200 + rand() % (1500-1200));
    }

    // Stores the sorted list of scores in the score array
    for(int k =0; k < NumRows; ++k){
        score[k] = sortedScores.top();
        sortedScores.pop();
    }

    // Calls for the creation of 10 rows of info for the QTableWidget
    for (int i = 0; i < NumRows; ++i){
        createRandomScoreTable(i, score);
    }

    QDataStream out(this);
    out << quint16(0xFFFF);
    close();
}

void ClientSocket::createRandomScoreTable(int i, const quint16 score[]){
    // Creates a list of names for the global scores table
    QString list[20] = {"xX1337_QwikSkopurzxX", "getonmylevel69", "Shadynasty", "Ki11ahEbaw1a", "xxL3thalKi11Axx",
                        "NuBSaUc3", "PR0GAEMUR", "L3g1taSSaSS1N", "BigNip5", "2HuryBawls", "Privat3memberS",
                        "zZELITESNIPERZz", "SeismicF4ppuR", "yoloSwaggins", "getpwnt683214", "L3G4LIZ3IT",
                        "n00bs4lunch", "XCr4ZYjok3RX", "Sk8tr4L1Fe", "ThaaJusHapened"};

    // Randomizes an integer to choose a random name from QString list
    int randomize = rand() % 20;
    QString name = list[randomize];

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);

    // Sends rank number, name, and score to client
    out << quint16(0) << quint8(i+1) << name << score[i];
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write(block);
}

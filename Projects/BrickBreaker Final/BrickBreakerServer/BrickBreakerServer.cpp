#include <QtCore>
#include "BrickBreakerServer.h"
#include "ClientSocket.h"

BrickBreakerServer::BrickBreakerServer(QObject *parent)
    : QTcpServer(parent){}

BrickBreakerServer::~BrickBreakerServer(){}

void BrickBreakerServer::incomingConnection(int socketId){
    ClientSocket *socket = new ClientSocket(this);
    socket->setSocketDescriptor(socketId);
}

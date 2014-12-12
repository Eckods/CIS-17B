#ifndef BRICKBREAKERSERVER_H
#define BRICKBREAKERSERVER_H

#include <QTcpServer>

class BrickBreakerServer : public QTcpServer
{
    Q_OBJECT

public:
    BrickBreakerServer(QObject *parent = 0);
    ~BrickBreakerServer();

private:
    void incomingConnection(int socketId);
};
#endif // BRICKBREAKERSERVER_H

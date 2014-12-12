#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QTcpSocket>

class QDate;
class QTime;

class ClientSocket : public QTcpSocket
{
    Q_OBJECT

public:
    ClientSocket(QObject *parent = 0);
    ~ClientSocket();

private slots:
    void readClient();

private:
    enum {NumRows = 10};

    void createRandomScoreTable(int i, const quint16 score[10]);

    quint16 nextBlockSize;
};
#endif // CLIENTSOCKET_H



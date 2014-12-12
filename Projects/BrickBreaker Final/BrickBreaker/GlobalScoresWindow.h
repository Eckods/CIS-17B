#ifndef GLOBALSCORESWINDOW_H
#define GLOBALSCORESWINDOW_H

#include <QDialog>
#include <QTcpSocket>

class QTableWidget;
class QPushButton;

class GlobalScoresWindow :public QDialog{
    Q_OBJECT

public:
    explicit GlobalScoresWindow(QWidget *parent = 0);
    ~GlobalScoresWindow();

private slots:
    void establishConnection();
    void closeConnection();
    void updateScoreTable();
    void sendRequest();
    void connectionError();

private:
    QTableWidget *table;
    QStringList tableHeader;
    QPushButton *searchButton;
    QPushButton *stopButton;
    QPushButton *quitButton;
    QTcpSocket tcpSocket;
    quint16 nextBlockSize;
};
#endif // GLOBALSCORESWINDOW_H

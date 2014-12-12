#include "GlobalScoresWindow.h"
#include <QtGui>
#include <QtNetwork>

GlobalScoresWindow::GlobalScoresWindow(QWidget *parent)
    : QDialog(parent){
    // Creates the 3 buttons that will be used in the dialog window
    searchButton = new QPushButton(tr("Search"));
    stopButton = new QPushButton(tr("Stop"));
    quitButton = new QPushButton(tr("Quit"));
    stopButton->setEnabled(false);

    connect(searchButton, SIGNAL(clicked()), this, SLOT(establishConnection()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    // Sets up a table widget for the global scoreboard
    table = new QTableWidget(this);
    table->setColumnCount(3);
    tableHeader << "Rank" << "Name" << "Score";
    table->setHorizontalHeaderLabels(tableHeader);
    table->verticalHeader()->setVisible(false);
    table->setFixedHeight(342);

    // Creates the layout for the Global Scores window
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addSpacing(6);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addSpacing(250);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addSpacing(20);
    mainLayout->addWidget(table, 0, Qt::AlignVCenter);
    mainLayout->addSpacing(6);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addSpacing(20);
    setLayout(mainLayout);

    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(sendRequest()));
    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(updateScoreTable()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(connectionError()));

    // Sets the title and size of the window
    setWindowTitle("Global High Scores");
    setFixedSize(450, 400);
}

GlobalScoresWindow::~GlobalScoresWindow(){}

void GlobalScoresWindow::sendRequest(){
    // Creates a block to send to the server
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << quint16(0);
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket.write(block);

    qDebug() << "Sending request...";
}

void GlobalScoresWindow::establishConnection(){
    // Connects to a local server
    tcpSocket.connectToHost(QHostAddress::LocalHost, 6178);

    // Sets the row count to 0 to reuse 10 rows on table widget
    table->setRowCount(0);

    // Disables the search button and enables the stop button
    searchButton->setEnabled(false);
    stopButton->setEnabled(true);
    connect(stopButton, SIGNAL(clicked()), this, SLOT(closeConnection()));

    nextBlockSize = 0;
}

void GlobalScoresWindow::closeConnection(){
    // Re-enables the search button and disables the stop button
    searchButton->setEnabled(true);
    stopButton->setEnabled(false);

    // Closes the connection
    tcpSocket.close();
}

void GlobalScoresWindow::updateScoreTable(){
    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_3);

        forever{
            int row = table->rowCount();

            // Until it gets to the final block, keeps retrieving information from server
            if (nextBlockSize == 0){
                if (tcpSocket.bytesAvailable() < sizeof(quint16))
                    break;
                in >> nextBlockSize;
            }
            if (nextBlockSize == 0xFFFF){
                closeConnection();
                break;
            }
            if (tcpSocket.bytesAvailable() < nextBlockSize)
                break;

            // Sets up a to store info from server per each field on the table
            quint8 ranking;
            QString name;
            quint16 score;

            // Retrieves ranking, name and score info from server
            in >> ranking >> name >> score;

            // Adds a new row to the table
            table->setRowCount(row + 1);

            // Stores ranking, name, and score info in their respective fields
            QStringList fields;
            fields << QString::number(ranking)
                   << name
                   << QString::number(score);

            for (int i = 0; i < fields.count(); ++i)
                table->setItem(row, i, new QTableWidgetItem(fields[i]));

            nextBlockSize = 0;
        }
}

void GlobalScoresWindow::connectionError()
{
    // Displays an error message regarding the connection and closes it
    qDebug() << tcpSocket.errorString();
    closeConnection();
}

#include "HighScoreWindow.h"
#include <QtGui>
#include <QtSql>

HighScoreWindow::HighScoreWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the database connectivity
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "defaultConn2");

    // Testing on local...
    //db.setHostName("localhost");
    //db.setDatabaseName("test");
    //db.setUserName("root");
    //db.setPassword("---");

    // Class connection...
    db.setHostName("209.129.8.5");
    db.setPort(3306);
    db.setDatabaseName("48597");
    db.setUserName("48597");
    db.setPassword("48597csc17b");

    // Holds the info for the query set up
    QString queryText = "SELECT `entity_player_brickbreaker`.`name`, `entity_scores_brickbreaker`.`score`, `entity_scores_brickbreaker`.`date_time` FROM `"
            "48597`.`xref_player_scores_brickbreaker` AS `xref_player_scores_brickbreaker`, `48597`.`entity_player_brickbreaker` AS `entity_player_brickbreaker`,"
            "`48597`.`entity_scores_brickbreaker` AS `entity_scores_brickbreaker` WHERE `xref_player_scores_brickbreaker`.`player_id` = `entity_player_brickbreaker`.`player_id`"
            "AND `xref_player_scores_brickbreaker`.`result_id` = `entity_scores_brickbreaker`.`result_id` ORDER BY `entity_scores_brickbreaker`.`score` DESC";

    // Sets up a table widget for the database scores
    scoreTable = new QTableWidget(this);
    scoreTable->setColumnCount(3);
    scoreTableHeader << "Rank" << "Name" << "Score";
    scoreTable->setHorizontalHeaderLabels(scoreTableHeader);
    scoreTable->verticalHeader()->setVisible(false);
    scoreTable->setFixedSize(300, 342);

    if (db.open()){
        qDebug() << "Opened Database";
        QSqlQuery *query = new QSqlQuery(QSqlDatabase::database("defaultConn2"));
        int row = 0;

        // Uses a query to grab info from DB tables and store them onto the table's fields
        if (query->exec(""+queryText+"")){
            while (query->next() && row < 10){
                scoreTable->setRowCount(row + 1);

                // Stores ranking, name, and score info into their respective fields
                QStringList fields;
                fields << QString::number(row + 1)
                       << query->value(0).toString()
                       << query->value(1).toString();

                for (int j = 0; j < fields.count(); j++){
                    scoreTable->setItem(row, j, new QTableWidgetItem(fields[j]));
                }
                   row++;
            }
        }
    }

    else{
        qDebug() << "Error: " << db.lastError().text();
    }
    // Creates a button box with an Ok & Cancel button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Refreshes the table
    scoreTable->viewport()->update();

    // Creates the layout for the High Score window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addSpacing(20);
    layout->addWidget(scoreTable, 3, Qt::AlignHCenter);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    // Sets the title of the High Score window
    setWindowTitle(tr("High Scores"));
    setFixedSize(400,440);
    db.close();
}

HighScoreWindow::~HighScoreWindow(){
    QSqlDatabase::removeDatabase("defaultConn2");
}

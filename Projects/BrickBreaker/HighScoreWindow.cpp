#include "HighScoreWindow.h"
#include <QtGui>

HighScoreWindow::HighScoreWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for the About information
    nameLabel = new QLabel(tr("Enter your name: "));
    nameLabel->setStyleSheet("QLabel{color: white}");

    // Creates a button box with an Ok & Cancel button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Adds a line edit for name entry
    nameEntry = new QLineEdit;
    nameEntry->setEnabled(false);

    // Adds a text browser for the scores to be output on
    scoreTable = new QTextBrowser;

    // Reads in high scores from resource file
    QFile file(":/Resource/highscores.txt");

    // Checks to see if file can be opened, if not, displays error
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0, "Error", file.errorString());

    // Outputs all lines in the text file
    QTextStream in(&file);
    scoreTable->setText(in.readAll());

    // Creates the layout for the High Score window
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(nameLabel);
    hLayout->addWidget(nameEntry);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(hLayout);
    layout->addSpacing(20);
    layout->addWidget(scoreTable, 3, Qt::AlignHCenter);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    // Sets the title of the About window
    setWindowTitle(tr("High Scores"));
    setFixedSize(400,250);

    // Closes text file
    file.close();
}

HighScoreWindow::~HighScoreWindow(){}

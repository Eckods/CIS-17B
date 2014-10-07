#include <QtGui>
#include "MainWindow.h"
#include "AboutWindow.h"
#include "HighScoreWindow.h"

MainWindow::MainWindow(){
    // Creates the 3 buttons that go on the main window
    start = new QPushButton(tr("&Start"));
    start->setFixedSize(140,40);
    start->setFont(QFont("MS Shell Dlg 2", 10, QFont::Bold));
    start->setStyleSheet("QPushButton{background-image:url(:/Resource/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/Resource/images/Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/Resource/images/Clicked.png);}");
    connect(start, SIGNAL(clicked()), this, SLOT(startButtonClicked()));

    viewHighScores = new QPushButton(tr("&View High Scores"));
    viewHighScores->setFixedSize(140,40);
    viewHighScores->setFont(QFont("MS Shell Dlg 2", 10, QFont::Bold));
    viewHighScores->setStyleSheet("QPushButton{background-image:url(:/Resource/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                                  "QPushButton:hover{background-image:url(:/Resource/images/Hover.png);}"
                                  "QPushButton:pressed{background-image:url(:/Resource/images/Clicked.png);}");
    connect(viewHighScores, SIGNAL(clicked()), this, SLOT(viewHighScoresButtonClicked()));

    quit = new QPushButton(tr("&Quit"));
    quit->setFixedSize(140,40);
    quit->setFont(QFont("MS Shell Dlg 2", 10, QFont::Bold));
    quit->setStyleSheet("QPushButton{background-image:url(:/Resource/images/Exit.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/Resource/images/Exit-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/Resource/images/Exit-Clicked.png);}");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Creates a label for the game's name
    titleName = new QLabel(tr("Pending Title Name"));
    titleName->setFixedSize(480,130);
    titleName->setFont(QFont("MS Shell Dlg 2", 36, QFont::Bold));
    titleName->setStyleSheet("QLabel{color:white}");

    // Sets up the layout for the main window
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(titleName, 10, Qt::AlignHCenter);
    buttonLayout->addWidget(start, 0, Qt::AlignHCenter);
    buttonLayout->addWidget(viewHighScores, 0, Qt::AlignHCenter);
    buttonLayout->addWidget(quit, 0, Qt::AlignHCenter);
    menuWidget = new QWidget;
    menuWidget->setLayout(buttonLayout);
    setCentralWidget(menuWidget);

    // Calls the function that creates the actions for the menu bar, the menu bar, & status bar
    createActions();
    createMenus();
    createStatusBar();

    // Sets the title, background, & window size
    setWindowTitle(tr("Brick Breaker"));
    setStyleSheet("QMainWindow{background-image:url(:/Resource/images/Background.png)}");
    setFixedSize(600,450);
}

MainWindow::~MainWindow(){}

void MainWindow::startButtonClicked(){
    // Hides buttons to use same window for game
    titleName->hide();
    start->hide();
    viewHighScores->hide();
    quit->hide();
}

void MainWindow::viewHighScoresButtonClicked(){
    HighScoreWindow highScoreWindow;
    highScoreWindow.setModal(true);
    highScoreWindow.setStyleSheet("QDialog{background-image:url(:/Resource/images/Background.png)}");
    highScoreWindow.exec();
}

void MainWindow::createMenus(){
    // Adds a Game & About option to the menu bar
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(returnAct);
    gameMenu->addAction(exitAct);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAct);
}

void MainWindow::createActions(){
    // Allows the user to return to menu
    returnAct = new QAction(tr("&Back to Main Menu"), this);
    returnAct->setShortcut(tr("Ctrl+Z"));
    returnAct->setStatusTip(tr("Return to main menu"));
    connect(returnAct, SIGNAL(triggered()), this, SLOT(backToMainMenu()));

    // Allows the user to exit the game through the menu bar
    exitAct = new QAction(tr("&Exit Game"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    // Allows the user to see the About info about the application
    aboutAct = new QAction(tr("&About Game"), this);
    aboutAct->setStatusTip(tr("Show info about game"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutGame()));
}
void MainWindow::createStatusBar(){
    // Displays the status bar on the bottom of the window w/ white font for status tips
    statusBar()->showMessage(tr(""));
    statusBar()->setStyleSheet("QStatusBar{color: white}");
}

void MainWindow::aboutGame(){
    AboutWindow aboutWindow;
    aboutWindow.setModal(true);
    aboutWindow.setStyleSheet("QDialog{background-image:url(:/Resource/images/Background.png)}");
    aboutWindow.exec();
}

void MainWindow::backToMainMenu(){
    // Redisplays the hidden buttons/labels
    titleName->show();
    start->show();
    viewHighScores->show();
    quit->show();
}

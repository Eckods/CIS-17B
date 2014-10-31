#include <QtGui>
#include "MainWindow.h"
#include "AboutWindow.h"
#include "HighScoreWindow.h"
#include "NoteWindow.h"

MainWindow::MainWindow(){
    // Calls the functions that creates the widgets for the stack, menu bar, menu bar actions, & status bar
    createMainWindowMenu();
    createGameWidget();
    createActions();
    createMenus();
    createStatusBar();

    // Creates a stacked widget as the central widget that holds the menu and game widgets
    stack = new QStackedWidget();
    stack->addWidget(menuWidget);
    stack->addWidget(gameWidget);
    setCentralWidget(stack) ;

    // Sets the title, background, & window size
    setWindowTitle(tr("Brick Break"));
    setStyleSheet("QMainWindow{background-image:url(:/Resource/images/Background.png)}");
    setFixedSize(600,450);
}

MainWindow::~MainWindow(){}

void MainWindow::createMainWindowMenu(){
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
    QPixmap titleImage(":/Resource/images/BrickBreak.png");
    titleName = new QLabel(tr(""));
    titleName->setPixmap(titleImage);
    titleName->setFixedSize(476,148);

    // Sets up the layout for the main window
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(titleName, 10, Qt::AlignHCenter);
    buttonLayout->addWidget(start, 0, Qt::AlignHCenter);
    buttonLayout->addWidget(viewHighScores, 0, Qt::AlignHCenter);
    buttonLayout->addWidget(quit, 0, Qt::AlignHCenter);
    menuWidget = new QWidget;
    menuWidget->setLayout(buttonLayout);
}

void MainWindow::createGameWidget(){
    // Creates a new process to be called
    QProcess *process = new QProcess;

    // Holds the path to the CreateTextFile.exe
    QString path = "./debug";
    path.append("/CreateTextFile.exe");

    // Displays the path to exe file
    //qDebug() << path;

    // Runs the CreateTextFile.exe
    process->start("CreateTextFile.exe");

    // If the program fails to start, display an error message and exit the program
    if (process->waitForStarted() == false){
        qDebug() << "Error starting CreateTextFile.exe";
        qDebug() << process->errorString();
        exit (-1);
    }

    // If the program runs, display a message saying it ran fine
    if (process->waitForStarted() == true){
        qDebug() << "Running CreateTextFile.exe";
    }

    // Close the .exe file after it has created the Instructions text file needed
    qDebug() << "Closing CreateTextFile.exe";
    process->close();

    // Creates a variable that will hold the path to the Instructions text file generated from process
    QFile text("C:/instructions.txt");

    // Checks to see if file can be opened, if not, displays error
    if(!text.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0, "Error", text.errorString());

    // Creates the instructions label that will appear besides the game
    QLabel *instructions = new QLabel;

    // Outputs all lines in the text file
    instructions->setText(text.readAll());

    //QLabel *instructions = new QLabel(tr("Press Space to start the game. Move the paddle using the <b>left</b> and <b>right arrow keys</b> on the keyboard. "
    //                                     "Upon gameover and/or entry of high score, press <b>space</b> again to reset the game or click the reset button."));
    instructions->setStyleSheet("QLabel{color: white}");
    instructions->setFont(QFont("MS Shell Dlg 2", 12));
    instructions->setFixedWidth(200);
    instructions->setWordWrap(true);

    // Creates a label that will display the user's score for each brick destroyed
    QLabel *scoreLabel = new QLabel(tr("Score: "));
    scoreLabel->setStyleSheet("QLabel{color: white}");
    scoreLabel->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    scoreLabel->setFixedHeight(20);

    scoreCount = new QLabel(tr(""));
    scoreCount->setStyleSheet("QLabel{color: white}");
    scoreCount->setFrameShape(QFrame::Box);
    scoreCount->setFrameShadow(QFrame::Sunken);
    scoreCount->setFixedSize(200, 60);

    // Creates a temporary push button to act as a filler for the brick break game
    QPushButton *tempButton = new QPushButton(tr("Filler for Game Space"));
    tempButton->setFixedSize(330, 392);

    // Creates a reset button that resets the game if clicked
    resetGame = new QPushButton(tr("&Reset"));
    resetGame->setFixedSize(140,40);
    resetGame->setFont(QFont("MS Shell Dlg 2", 10, QFont::Bold));
    resetGame->setStyleSheet("QPushButton{background-image:url(:/Resource/images/Exit.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/Resource/images/Exit-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/Resource/images/Exit-Clicked.png);}");

    // Sets up the group box and layout for the Game widget
    scoreGroupBox = new QGroupBox(tr(""));
    scoreGroupBox->setStyleSheet("QGroupBox{color:white}");

    QVBoxLayout *gameVLayout = new QVBoxLayout;
    gameVLayout->addSpacing(15);
    gameVLayout->addWidget(scoreLabel, 0, Qt::AlignHCenter);
    gameVLayout->addWidget(scoreCount, 0, Qt::AlignHCenter);
    gameVLayout->addWidget(instructions, 0, Qt::AlignHCenter);
    gameVLayout->addWidget(resetGame, 0, Qt::AlignHCenter);
    gameVLayout->addSpacing(15);

    scoreGroupBox->setLayout(gameVLayout);
    scoreGroupBox->setFixedWidth(240);

    QHBoxLayout *gameHLayout = new QHBoxLayout;
    gameHLayout->addWidget(tempButton, 0, Qt::AlignLeft);
    gameHLayout->addWidget(scoreGroupBox);

    gameWidget = new QWidget;
    gameWidget->setLayout(gameHLayout);
}

void MainWindow::startButtonClicked(){
    // Changes to the game menu page
    int nextPage = stack->currentIndex() + 1;
    if (nextPage >= stack->count())
        nextPage = 0;
    stack->setCurrentIndex(nextPage);
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
    gameMenu->addSeparator();
    gameMenu->addAction(exitAct);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAct);

    miscMenu = menuBar()->addMenu(tr("&Misc"));
    miscMenu->addAction(noteAct);
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

    // Brings up a note dialog box
    noteAct = new QAction(tr("&Notes"), this);
    noteAct->setShortcut(tr("Ctrl+N"));
    noteAct->setStatusTip(tr("Create a note text file"));
    connect(noteAct, SIGNAL(triggered()), this, SLOT(takeNotes()));
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
    int prevPage = stack->currentIndex() + 1;

    // Displays a message box asking user if they want to return to Main menu if on Game page
    if (prevPage >= stack->count()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Return",
                             "Are you sure you want to return to main menu?",
                             QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            prevPage = 0;
            stack->setCurrentIndex(prevPage);
        }
    }
    // Leaves the user on Main menu if they are currently on it
    else
        prevPage = 0;
        stack->setCurrentIndex(prevPage);
}

void MainWindow::takeNotes(){
    NoteWindow noteWindow;
    noteWindow.setModal(true);
    noteWindow.setStyleSheet("QDialog{background-image:url(:/Resource/images/Background.png)}");
    noteWindow.exec();
}

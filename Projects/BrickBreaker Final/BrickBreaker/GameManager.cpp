#include "GameManager.h"
#include <QtGui>
#include <QtSql>
#include "HighScoreWindow.h"

GameManager::GameManager(QWidget *parent)
    : QWidget(parent){
    // Initializes a ball and paddle
    ball = new Ball();
    paddle = new Paddle();

    // Sets up 30 bricks in a 6x5 arrangement
    int k = 0;
    for(int i = 0; i < NumRows; i++){
        for (int j = 0; j < NumCols; j++){
            // 58 is +2 spaces added to Brick's width of 56, 19 is spaces from left edge
            // 16 is +2 spaces added to Brick's height of 14, 40 is space from the top
            bricks[k] = new Brick(j*58+19, i*16+20);
            k++;
        }
    }
    // Sets the remaining variables
    x = 0;
    gameStart = false;
    gameOver = false;
    gameWon = false;
    gamePaused = false;
    userScore = 0;

    // Creates a label that will display the user's score for each brick destroyed
    scoreDisplay = new QLabel("");
    scoreDisplay->setText(getScore());
    scoreDisplay->setStyleSheet("QLabel{color: white; qproperty-alignment: 'AlignHCenter | AlignVCenter';}");
    scoreDisplay->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    scoreDisplay->setFrameShape(QFrame::Box);
    scoreDisplay->setFrameShadow(QFrame::Sunken);
    scoreDisplay->setFixedSize(200, 60);

    // Creates a reset button that resets the game if clicked
    resetButton = new QPushButton(tr("&Reset"));
    resetButton->setFixedSize(140,40);
    resetButton->setFont(QFont("MS Shell Dlg 2", 10, QFont::Bold));
    resetButton->setStyleSheet("QPushButton{background-image:url(:/Resource/images/Exit.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/Resource/images/Exit-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/Resource/images/Exit-Clicked.png);}");
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetGame()));

    setFixedSize(330,392);
}

GameManager::~GameManager(){
    // Deletes the paddle, ball, and brick from memory
    delete paddle;
    delete ball;
    for(int i = 0; i < NumBricks; i++){
        delete bricks[i];
    }
    QSqlDatabase::removeDatabase("defaultConn");
    QSqlDatabase::removeDatabase("defaultConn2");
}

void GameManager::paintEvent(QPaintEvent *event){
    QPainter paint(this);
    // Loads up the paddle and ball
    paint.drawImage(ball->getBall(), ball->getImage());
    paint.drawImage(paddle->getPaddle(), paddle->getImage());

    // Loads up the bricks
    for(int i = 0; i < NumBricks; i++){
        if(!bricks[i]->isDestroyed())
            paint.drawImage(bricks[i]->getBrick(), bricks[i]->getImage());
    }
}

void GameManager::timerEvent(QTimerEvent *event){
    // Calls the Ball's automove function to translate it's position
    ball->autoMove();

    // Checks for the Ball's collision with the bricks and paddle
    checkForCollision();

    // Paints the paddle, ball, and bricks again for each movement made
    repaint();
}

void GameManager::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    // If left arrow key is pressed, moves the paddle left
    case Qt::Key_Left:{
        int x = paddle->getPaddle().x();
        for(int i = 0; i < 5; i++)
            paddle->movePaddleLeft(x-4);
        break;
    }
    // If right arrow key is pressed, moves the paddle right
    case Qt::Key_Right:{
        int x = paddle->getPaddle().x();
        for(int i = 0; i < 5; i++)
            paddle->movePaddleRight(x+4);
        break;
    }
    // If the P key is pressed, pauses the game
    case Qt::Key_P:{
        pauseGame();
        break;
    }
    // If the R key is pressed, resets the game
    case Qt::Key_R:{
        resetGame();
        QSqlDatabase::removeDatabase("defaultConn");
        QSqlDatabase::removeDatabase("defaultConn2");
        break;
    }
    // If the space button is pressed, starts the game
    case Qt::Key_Space:{
        startGame();
        QSqlDatabase::removeDatabase("defaultConn");
        QSqlDatabase::removeDatabase("defaultConn2");
        break;
    }
    default:
        QWidget::keyPressEvent(event);
    }
}

void GameManager::startGame(){
    // If the game starts, resets the paddle and ball back to their original positions
    if (!gameStart){
        paddle->resetPaddle();
        ball->resetBall();

    // Initializes the brick's destroyed state to false
    for(int i = 0; i < NumBricks; i++)
        bricks[i]->setDestroyed(false);

    // Resets some variables and starts the game's timer
    gameStart = true;
    gameOver = false;
    gameWon = false;
    userScore = 0;
    scoreDisplay->setText(getScore());
    time = startTimer(8);
    }
}

void GameManager::endGame(){
    // Stops the game's timer and ends the game
    killTimer(time);
    gameOver = true;
    gameStart = false;
    saveScores();
}

void GameManager::winGame(){
    // Stops the game's timer and ends the game
    killTimer(time);
    gameWon = true;
    gameStart = false;
    saveScores();
}

void GameManager::pauseGame(){
    // If the game is not paused, start the timer
    if (gamePaused){
        time = startTimer(8);
        gamePaused = false;
    }
    // Stops the game's timer/ pauses the game
    else{
        gamePaused = true;
        killTimer(time);
    }
}

void GameManager::saveScores(){
    QString userName;

    // Pops up a input box for user to enter their name for a score record
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter your user name"), tr("Name:"), QLineEdit::Normal, QDir::home().dirName(), &ok);

    // If user hits Ok and they have written something in the line edit, save the record and display scores
    if (ok && !text.isEmpty()){
       userName = text;

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "defaultConn");
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

        if (db.open()){
            qDebug() << "Opened Database";
            QSqlQuery *query = new QSqlQuery(QSqlDatabase::database("defaultConn"));
            QDateTime dateTime = QDateTime::currentDateTime();
            QString text = dateTime.toString("yyyy-MM-dd hh:mm:ss");
            qDebug() << text;
            QString str = QString::number((userScore));

            // Inserts the user's entered name into the player table
            query->prepare("INSERT INTO entity_player_brickbreaker (name) VALUES (:name)");
            query->bindValue(":name", ""+userName+"");
            if(query->exec()){
                qDebug() << "Name saved";
            }
            else
                qDebug() << query->lastError();

            // Inserts the user's score and date_time into the score table
            query->prepare("INSERT INTO entity_scores_brickbreaker (score, date_time) VALUES (:score, :date_time);");
            query->bindValue(":score", ""+str+"");
            query->bindValue(":date_time", ""+text+"");
            if(query->exec()){
                qDebug() << "Score & time saved";
            }
            else
                qDebug() << query->lastError();

            // Inserts the player_id and result_id from the newly entered score into the xref table
            query->prepare("INSERT INTO xref_player_scores_brickbreaker (player_id, result_id) VALUES (LAST_INSERT_ID(), LAST_INSERT_ID());");
            if(query->exec()){
                qDebug() << "Xref ids saved";
            }
            else
                qDebug() << query->lastError();
        }
        db.close();
        HighScoreWindow *highWindow = new HighScoreWindow;
        highWindow->setModal(true);
        highWindow->setStyleSheet("QDialog{background-image:url(:/Resource/images/Background.png)}");
        highWindow->exec();
    }
}

void GameManager::checkForCollision(){
    // If the ball reaches beyond the game space, game is over
    if (ball->getBall().bottom() > 400)
        endGame();

    // Initializes a counter for the bricks
    int j = 0;

    // Checks through all the bricks and if 30 are destroyed, game is won
    for (int i = 0; i < NumBricks; i++){
        if (bricks[i]->isDestroyed())
            j++;
        if (j == NumBricks)
            winGame();
    }
    // If the ball hits a certain part on the paddle, it moves however many x and y integers designated
    if ((ball->getBall().intersects(paddle->getPaddle()))){
        int paddlePosition = paddle->getPaddle().left();
        int ballPosition = ball->getBall().left();

        // Sets up variables that section the paddle for ball collision movement
        int leftHalf = paddlePosition + 22;
        int middle = paddlePosition + 40;
        int rightHalf = paddlePosition + 62;

        // If the ball hits near the paddle's left half, ball bounces up and moves left
        if (ballPosition < leftHalf){
            ball->setXDir(-1);
            ball->setYDir(-1);
        }
        // If the ball hits near the paddle's center, ball bounces upwards only
        else if (ballPosition < middle){
            ball->setXDir(0);
            ball->setYDir(-1);
        }
        // If the ball hits the paddle's right half, ball bounces up and moves right
        else if (ballPosition < rightHalf){
            ball->setXDir(1);
            ball->setYDir(-1);
        }
    }

    for (int k = 0; k < NumBricks; k++){
        if ((ball->getBall().intersects(bricks[k]->getBrick()))){
            // Sets up variables for the ball's points of intersection
            int left = ball->getBall().left();
            int height = ball->getBall().height();
            int width = ball->getBall().width();
            int top = ball->getBall().top();

            // Ball is sectioned into 4 areas, top, left, right, and bottom
            // When a certain area of the ball contacts the bricks, it will move in a certain direction
            QPoint leftSide(left - 1, top);
            QPoint rightSide(left + width + 1, top);
            QPoint topSide(left, top - 1);
            QPoint bottomSide(left, top + height + 1);

            if (!bricks[k]->isDestroyed()){
                // If the ball's right side hits the brick, bounces back in left direction
                if (bricks[k]->getBrick().contains(leftSide))
                    ball->setXDir(1);
                // If the ball's left side hits the brick, bounces back in right direction
                else if (bricks[k]->getBrick().contains(rightSide))
                    ball->setXDir(-1);
                // If the ball's top side hits the brick, bounces downwards
                if (bricks[k]->getBrick().contains(topSide))
                    ball->setYDir(1);
                // If the ball's bottom side hits the brick, bounces upwards
                else if (bricks[k]->getBrick().contains(bottomSide))
                    ball->setYDir(-1);
                // If the brick is hit, set it to destroyed and increment the score
                bricks[k]->setDestroyed(true);
                userScore = userScore + 50;
                scoreDisplay->setText(getScore());
            }
        }
    }
}

QString const GameManager::getScore(){
    // Returns the current score as a QString
    QString str = QString::number((userScore));
    return str;
}

void GameManager::resetGame(){
    // If game has already started/ended, resets the paddle and ball back to their original positions
    if (gameStart || gameOver){
        paddle->resetPaddle();
        ball->resetBall();

    // Initializes the brick's destroyed state to false
    for(int i = 0; i < NumBricks; i++)
        bricks[i]->setDestroyed(false);

    // Resets some variables and starts the game's timer
    gamePaused = false;
    killTimer(time);
    gameStart = true;
    gameOver = false;
    gameWon = false;
    userScore = 0;
    scoreDisplay->setText(getScore());
    time = startTimer(8);
    }
}

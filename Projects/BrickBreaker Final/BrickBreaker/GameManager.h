#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Paddle.h"
#include "Brick.h"
#include "Ball.h"
#include <QWidget>
#include <QKeyEvent>

class QLabel;
class QPushButton;

class GameManager : public QWidget{
    Q_OBJECT

public:
    explicit GameManager(QWidget *parent = 0);
    ~GameManager();

    QLabel *scoreDisplay;
    QPushButton *resetButton;

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void startGame();
    void endGame();
    void winGame();
    void pauseGame();
    void saveScores();
    void checkForCollision();
    QString const getScore();

private slots:
    void resetGame();

private:
    enum {NumRows = 6, NumCols = 5, NumBricks = 30};

    Ball *ball;
    Paddle *paddle;
    Brick * bricks[NumBricks];
    int x;
    int time;
    int userScore;
    bool gameStart;
    bool gameOver;
    bool gameWon;
    bool gamePaused;
};
#endif // GAMEMANAGER_H

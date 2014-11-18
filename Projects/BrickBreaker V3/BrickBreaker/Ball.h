#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

class Ball{
public:
    Ball();
    ~Ball();

public:
    void setXDir(int);
    void setYDir(int);
    void moveUp(int);
    void moveDown(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();
    void resetBall();
    QRect getBall();
    QImage& getImage();

private:
    int moveX;
    int moveY;
    QImage ballImage;
    QRect ball;
};
#endif // BALL_H

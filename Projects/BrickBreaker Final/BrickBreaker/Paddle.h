#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

class Paddle{
public:
    Paddle();
    ~Paddle();
    QRect getPaddle();
    QImage& getImage();
    void movePaddleLeft(int);
    void movePaddleRight(int);
    void resetPaddle();

private:
    QImage paddleImage;
    QRect paddle;
};
#endif //PADDLE_H

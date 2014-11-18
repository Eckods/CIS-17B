#include "Ball.h"

Ball::Ball(){
    // Loads the image of the Ball
    ballImage.load("Resource/images/Brick.png");

    // Sets the Ball to move 1 space in the X-Y direction at a time (like Speed)
    moveX = 1;
    moveY = 1;

    // Sets the image of the Ball and resets it at the end of the call
    ball = ballImage.rect();
    resetBall();
}

Ball::~Ball() {}

void Ball::setXDir(int moveX){
    // Moves the Ball left/right some int value
    this->moveX = moveX;
}

void Ball::setYDir(int moveY){
    // Moves the Ball up/down some int value
    this->moveY = moveY;
}

void Ball::moveUp(int up){
    // Moves the Ball up some int value
    ball.moveTop(up);
}

void Ball::moveDown(int down){
    // Moves the Ball down some int value
    ball.moveBottom(down);
}

void Ball::moveLeft(int left){
    // Moves the Ball to the left some int value
    ball.moveLeft(left);
}

void Ball::moveRight(int right){
    // Moves the Ball to the right some int value
    ball.moveRight(right);
}

void Ball::autoMove(){
    // Move the Ball some int values in the X & Y direction
    ball.translate(moveX, moveY);

    // Allows the Ball to move up until it reaches the top edge of the game space (the 0 point)
    if (ball.top() == 0){
        moveY = 1;
    }

    // Allows the Ball to move right until it reaches the left edge of the game space (the 0 point)
    if (ball.left() == 0){
        moveX = 1;
    }

    // Allows the Ball to move right until it reaches the right edge of the game space (the 330 point)
    if (ball.right() == 330){
        moveX = -1;
    }
}

void Ball::resetBall(){
    // Loads the Ball in the middle of the game space
    ball.moveTo(165, 400);
}

QRect Ball::getBall(){
    // Returns the Ball rectangle
    return ball;
}

QImage & Ball::getImage(){
    // Returns the image of the Ball
    return ballImage;
}

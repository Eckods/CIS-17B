#include "Paddle.h"

Paddle::Paddle(){
    // Loads the image of the Paddle
    paddleImage.load(":Resource/images/Paddle.png");

    // Sets the Paddle image to the rectangle
    paddle = paddleImage.rect();
    resetPaddle();
}

Paddle::~Paddle(){}

QRect Paddle::getPaddle(){
    // Returns the Paddle rectangle
    return paddle;
}

QImage &Paddle::getImage(){
    // Returns the Paddle image
    return paddleImage;
}

void Paddle::movePaddleLeft(int left){
    // Moves the Paddle left as long as it is not at the leftmost point (4 spaces away from left edge of game space)
    if (paddle.left() >= 4)
        paddle.moveTo(left, paddle.top());
}

void Paddle::movePaddleRight(int right){
    // Moves the Paddle right as long as it is not at the rightmost point (4 spaces away from right edge of game space)
    if (paddle.right() <= 326)
        paddle.moveTo(right, paddle.top());
}

void Paddle::resetPaddle(){
    // Loads the Paddle in the middle of the game space
    paddle.moveTo(140, 380);
}

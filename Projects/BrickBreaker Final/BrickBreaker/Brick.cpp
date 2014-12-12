#include "Brick.h"

Brick::Brick(int x, int y){
    // Loads the image of the Brick
    brickImage.load(":Resource/images/Brick.png");

    // Sets the Brick's destroyed variable to FALSE initially
    destroyed = false;

    // Sets the image of the Brick and its coordinates
    brick = brickImage.rect();
    brick.translate(x, y);
}

Brick::~Brick(){}

QRect Brick::getBrick(){
    // Returns the Brick
    return brick;
}

QImage &Brick::getImage(){
    // Returns the image of the Brick
    return brickImage;
}

bool Brick::isDestroyed(){
    // Returns the bool value that checks if Brick is destroyed
    return destroyed;
}

void Brick::setDestroyed(bool destroyed){
    // Sets Brick to whatever bool value is held in the destroyed variable
    this->destroyed = destroyed;
}

#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QRect>

class Brick{
public:
    Brick(int, int);
    ~Brick();
    QRect getBrick();
    QImage& getImage();
    void resetBrick();
    bool isDestroyed();
    void setDestroyed(bool);

private:
    QImage brickImage;
    QRect brick;
    int position;
    bool destroyed;
};
#endif // BRICK_H

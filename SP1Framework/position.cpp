#include "position.h"

position::position()
{
    x = 0;
    y = 0;
}

position::~position()
{

}

void position::setPositionX(int x)
{
    this->x = x;
}

void position::setPositionY(int y)
{
    this->y = y;
}

int position::getPositionX(void)
{
    return x;
}

int position::getPositionY(void)
{
    return y;
}
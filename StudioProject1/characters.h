#pragma once
#include "position.h"
#include <string>
class characters
{
private:
    position characterPosition;
    std::string name;
public:
    void setPositionX(int x);
    void setPositionY(int y);
    int getPositionX();
    int getPositionY();
    void setName(std::string name);
    std::string getName();
};
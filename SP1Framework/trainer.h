#pragma once
#include "asciimon.h"
#include "characters.h"
class trainer : public characters
{
private:
    asciimon* asciimons[4];
    int items[6];
public:
    trainer();
    trainer(std::string name);
    void setAsciimon(int num, asciimon* asciimon, int level);
    void setItem(int num,int quantity);
    int getItem(int num);
};
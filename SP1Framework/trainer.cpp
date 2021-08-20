#include "trainer.h"

trainer::trainer(std::string name)
{
    for (int i = 0; i < 4; i++)
    {
        asciimons[i] = nullptr;
    }
    setName(name);
}

void trainer::setAsciimon(int num, asciimon* asciimon1, int level)
{
    if (num >= 0 && num < 4)
    {
        this->asciimons[num] = asciimon1;
        this->asciimons[num]->setLevel(level);
    }
}

void trainer::setItem(int num, int quanity)
{
    items[num] = quanity;
}

int trainer::getItem(int num)
{
    return items[num];
}
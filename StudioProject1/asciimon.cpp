#include "asciimon.h"
#include "move_1.h"

asciimon::asciimon()
{
    setName("Null");
    baseStats[0]=0;
    baseStats[1] = 0;
    baseStats[2] = 0;
    baseStats[3] = 0;
    baseStats[4] = 0;
    baseStats[5] = 0;
    setIvs();
    calcStats();
    setAllStats(); //includes setting current HP
    setLevel(0);
    setRarity(0);
    setType('N');
    learnableMoves[0] = new move_1;
    setCurrentMoves();
}

void asciimon::setName(std::string name)
{
    this->name = name;
}

/*void asciimon::setBaseStats(int* baseStats)
{
    for (int i = 0; i < 6; i++)
    {
        this->baseStats[i] = baseStats[i];
    }
}

void stats::setIncrement(int *statsIncrement)
{
    for (int i = 0; i < 6; i++)
    {
        this->statsIncrement[i] = statsIncrement[i];
    }
}*/

void asciimon::setIvs(void)
{
    for (int i = 0; i < 6; i++)
    {
        ivs[i] = area::randomiser(0, 31);
    }
}

void asciimon::calcStats(void)
{
    stat[0] = (2 * baseStats[0] + ivs[0] + 1) * level / 100 + level + 10;
    for (int i = 1; i < 6; i++)
    {
        stat[i] = (2 * baseStats[i] + ivs[i] + 1) * level / 100 + 5;
        //(ivs[i] + 31) / 31 * (baseStats[i] + lvl * statsIncrement[i]);
    }
}

void asciimon::setLevel(int level)
{
    this->level = level;
}

void asciimon::setRarity(int rarity)
{
    this->rarity = rarity;
}

void asciimon::setType(char type)
{
    this->type = type;
}

void asciimon::setCurrentMoves(void) //only for spawning new asciimon
{
    int pickedMove;
    if (level >= 5)
    {
        pickedMove = (level / 5); //newest move
    }
    else
    {
        pickedMove = 0;
    }
    for (int i = 0; (pickedMove >= 0) && (i < 3); i++)
    {
        currentMoves[i] = learnableMoves[pickedMove];
    }
}

void asciimon::modifyHealth(int change)
{
    currentHp += change; //if is damage done, change should be negative
}

std::string asciimon::getName()
{
    return name;
}
int asciimon::getCurrentHp()
{
    return currentHp;
}

int asciimon::getHp()
{
    return stat[0];
}
int asciimon::getAtk()
{
    return stat[1];
}
int asciimon::getSAtk()
{
    return stat[2];
}
int asciimon::getDef()
{
    return stat[3];
}
int asciimon::getSDef()
{
    return stat[4];
}
int asciimon::getSpd()
{
    return stat[5];
}
int asciimon::getLevel()
{
    return level;
}
int asciimon::getRarity()
{
    return rarity;
}
char asciimon::getType()
{
    return type;
}

moves* asciimon::getCurrentMoves(void)
{
    return *currentMoves;
}
#pragma once
#include <string>
#include "moves.h"
#include "area.h" //TEMPORARY!

class asciimon
{
protected:
    std::string name;
    int ivs[6];
    int baseStats[6];
    //int statsIncrement[6];
    int stat[6]; // 0 hp, 1 atk, 2 s.atk, 3 def, 4 s.def, 5 spd
    moves* learnableMoves[20];
    moves* currentMoves[3];
    moves selectedMove;
    int currentHp;
    int level;
    int rarity;
    char type;
    virtual void setAllStats(void) = 0; //defined in specific asciimon class
                                        //set all stats for all specific asciimon including current Hp

public:
    asciimon();
    void setName(std::string name); 
    //void setBaseStats(int* baseStats); //base stats get from asciimon
    //void setIncrement(int *statsIncrement); //increment (per lvl) = (base stat + IV)/50
    void setIvs(void); //randomly generate
    void calcStats(void); //HP = (2* base stat + IV + 1) * lvl / 100 + lvl + 10 (lvl get from asciimon)
                //other stats = (2* base stat + IV + 1) * lvl / 100 + 5 
    void setLevel(int level);
    void setRarity(int rarity);
    void setType(char type);
    void setCurrentMoves(void);

    void modifyHealth(int change); //if is damage done, change should be negative
    virtual asciimon* clone(void) = 0; //called when new asciimon is meant to spawn to create new asciimnon obj for battle interface

    std::string getName(void);
    int getCurrentHp(void);
    int getHp(void);
    int getAtk(void);
    int getSAtk(void);
    int getDef(void);
    int getSDef(void);
    int getSpd(void);
    int getLevel(void);
    int getRarity(void);
    char getType(void);
    moves* getCurrentMoves(void); //from here you can use index to call sepcific moves within list
};
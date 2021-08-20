#include "battle.h"
#include "trainer.h"
#include "asciimon.h"
#include "area.h" //TEMPORARY UNTIL MOVE RANDOMISER TO UTILITY CLASS WITH LOADDATA

std::string battle::atkMoveType = "FWGBMD";
std::string battle::sEffectiveType = "GFWDBM";
std::string battle::rEffectiveType = "WGFMDB";

battle::battle()
{

 
}

battle::~battle()
{
    
}

float battle::getTypeEffMultipler(moves* attack, asciimon* target) //take notes of 1 type only
{
    float multiplier = 1;
    //char moveType = 'F'; //TEMPORARY, NEED WAY TO GET MOVE TYPE CHAR
    if (sEffectiveType[atkMoveType.find(attack->getMoveType())] == target->getType()) //if move s effective against target
    {
        multiplier = 2;
    }
    else if (rEffectiveType[atkMoveType.find(attack->getMoveType())] == target->getType()) //if target resist move
    {
        multiplier = 0.5;
    }

    return multiplier;
}

bool battle::getSTABPresence(asciimon* attacker, moves* attack)
{
    bool STAB = false;
    if (attacker->getType() == attack->getMoveType()) //IMPORTANT: need a way to get move type
    {
        STAB = true;
    }
    return STAB;
}

int battle::getDamageDealt(asciimon* attacker, asciimon* target, moves* attack)
{
    int atkerAPower, tarDfns, random, atksPower;
    float STAB, damageDealt;
    //calculate type effectiveness base on movetype and target mon type
    //calculate STAB base on move type and attacker mon type


    int atkLvl = attacker->getLevel();

    //check if move used is Sp or Phys
    //char moveType = 'S'; //substitute
    if (attack->getAtkType() == 'S') //special attack
    {
        atkerAPower = attacker->getSAtk();
        tarDfns = target->getSDef();
    }
    else //physical attack
    {
        atkerAPower = attacker->getAtk();
        tarDfns = target->getDef();
    }

    atksPower = attack->getAtkPower();

    if (getSTABPresence(attacker, attack)) //got STAB
    {
        STAB = 1.5;
    }
    else //no STAB
    {
        STAB = 1;
    }

    float typeEffectiveness = getTypeEffMultipler(attack, target); 

    random = area::randomiser(217, 255); //random number to randomise damage
                                    //so same attack from same asciimon
                                    //won't always deal the same damage

    damageDealt = ((((2 * atkLvl/ (5+2)) * atkerAPower * atksPower / tarDfns / 50) + 2 ) * STAB * typeEffectiveness / 10 * random / 255);
    return (int)(-1 * damageDealt); //returns negative to signify loss in HP
}

bool battle::getStatusPresence(moves* attack)
{
    int randValue = area::randomiser(1, 100); //percentage odds
    //int statusProb = 20; //TEMPORARY UNTIL MOVE OBJ ADDED
    return (randValue <= attack->getStatEffProbability()); //if number generator is =
                                    //or less than percentage chance
                                    //status effect is in effect
}

void battle::attack(asciimon* attacker, asciimon* target, moves* attack)
{
    target->modifyHealth(getDamageDealt(attacker, target, attack));
    if (getStatusPresence(attack)) //if status in effect
    {
        //need a setStatus in asciimon, using status from move
    }
}
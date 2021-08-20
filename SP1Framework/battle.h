#pragma once
#include "asciimon.h"
#include "moves.h"
#include <string>

class battle
{
private:
    static std::string atkMoveType; //string storing all move types in a specific order
    static std::string sEffectiveType; //stores move types in order following atkMoveType: 
                                //types that are weak to its same index in atkMoveType
    static std::string rEffectiveType; //stores move types in order following atkMoveType: 
                                //types that are resistance to its same index in atkMoveType

    static float getTypeEffMultipler(moves* attack, asciimon* target); 
    static bool getSTABPresence(asciimon* attacker, moves* attack); //returns true if asciimon 
                                        //is same type as the move it 
                                        //is using
    static int getDamageDealt(asciimon* attacker, asciimon* target, moves* attack); //battle 
                                                            //damage
                                                            //calculation
    static bool getStatusPresence(moves* attack); //calculate if status effect
                                                //gets thru or not

public:
    battle();
    ~battle();
    static void attack(asciimon* attacker, asciimon* target, moves* attack); 
};
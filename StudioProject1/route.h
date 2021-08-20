#pragma once
#include "area.h"
#include "asciimon.h"
#include <time.h>

class route : public area
{
protected:
    asciimon* spawnList[10]; //list of spawnable asciimon in the area
                            //10 is temporary
    int encounterOddsCount; //if rarity is 3, add 1, rarity 1, add 3. 
                            //than later randomise a number from this tota
                            //to figure out which asciimon to spawn
                            //asciimon of rarity 3 will have 1 number in 
                            //the running to represent them, etc
    int* asciiEncounterList;
    int minAsciimonLvl; //for the range of lvls for the asciimon that
    int maxAsciimonLvl; //spawn in the specific route
    virtual void setSpawnList(void) = 0; //set list of available asciimon 
                                        //in the area overriden in the 
                                        //derived classes
    void setAsciimonOdds(void); //sets rarity of asciimon to the route 
                                //sets the numbers to represent which 
                                //asciimon when randomising
                                //only used in the constructor

public:
    route();
    virtual ~route();
    asciimon* getRandomAsciimon(void); //randomly gets a number representing 
                                //one of the available asciimon that will 
                                //spawn (can be called in game to return 
                                //exact asciimon object to create specific
                                //asciimon object by calling its clone function)
    int getLvlOfSpawnedAsciimon(void); //picks a random lvl within range
                                        //for the newly spawned asciimon
};
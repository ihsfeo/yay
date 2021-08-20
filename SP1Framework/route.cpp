#include "route.h"
#include "asciimon.h"


route::route()
{
    encounterOddsCount = 0;
    minAsciimonLvl = 0; //will get chaned in individual routes
    maxAsciimonLvl = 0;
    for (int i = 0; i < 10; i++)
    {
        spawnList[i] = nullptr; //initialising spawnList
    }
    setSpawnList();
    setAsciimonOdds();
}

route::~route()
{
    delete asciiEncounterList;
    for (int i = 0; i < 10; i++)
    {
        if (spawnList[i] != nullptr)
        {
            delete spawnList[i];
        }
    }
}

//can shift below function into constructor?
void route::setAsciimonOdds(void) 
//needs the rarity rate of asciimon and sets it to the route 
//sets the numbers to represent which asciimon when randomising
{
    int encounterIdx = 0;

    //generate asciiEncounterList
    //if an asciimon's rarity is 3 (rare), allocate only one cell for it in the asciiEncounterList, 
    //the value in the cell is the index of this ascimmon in the spawnList array
    //if an asciimon's rarity is 1 (common), allocate three cells for it in the aciiEncounterList,
    //all with same index value to the spawnList
    for (int i = 0; i < 10; i++)
    {
        if (spawnList[i] != nullptr)
        {
            encounterOddsCount += 4 - spawnList[i]->getRarity();
        }
    }
    asciiEncounterList = new int[encounterOddsCount];


    for (int i = 0; i < (sizeof(spawnList)) / sizeof(spawnList[0]); i++) 
    //for all elements in spawnList
    {
        if (spawnList[i] != nullptr) //if the element holds an asciimon
        {
            //adds 1 for rare, 2 for uncommon, 3 for common
            //total odds used for random asciimon selection for spawn

            //limited by the rarity (loops for as many times as the rarity of the asciimon)
            for (int j = 0; j < (4 - spawnList[i]->getRarity()); j++)
            {
                asciiEncounterList[encounterIdx++] = i;
            }
        }
        //^^thought process: if i could use the final encounterOddsCount 
        //as the size of an array to hold the index of the asciimon in spawnList
        // in respect to rarity (like it will hold 3 of the same common asciimon 
        //and 1 of a rare asciimon etc), I could use the randomly 
        //generated number as the locating number within said array
    }
}

asciimon* route::getRandomAsciimon(void)
{
    int randValue = randomiser(0, (encounterOddsCount - 1));

    return spawnList[asciiEncounterList[randValue]];
}

int route::getLvlOfSpawnedAsciimon(void)
{
    int randValue = randomiser(minAsciimonLvl, maxAsciimonLvl);
    return randValue;
}
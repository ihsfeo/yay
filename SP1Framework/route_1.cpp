#include "route_1.h"

route_1::route_1()
{
    minAsciimonLvl = 2;
    maxAsciimonLvl = 9;
    areaName = "Route 1";
    setMap("./Area Maps/route_1.txt");
    charactersPresent[0] = new characters; //change to characters present
}

void route_1::setSpawnList(void)
{
    //spawnList[0] = new asciimon; //change to available asciimon
}

route_1::~route_1()
{

}
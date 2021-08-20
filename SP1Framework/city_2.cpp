#include "city_2.h"
#include "characters.h"
#include "non_trainer.h"

city_2::city_2()
{
	areaName = "Venus City";
	setMap("./Area Maps/city_2.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_2::~city_2()
{

}
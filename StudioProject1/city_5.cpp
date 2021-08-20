#include "city_5.h"
#include "characters.h"
#include "non_trainer.h"

city_5::city_5()
{
	areaName = " City";
	setMap("./Area Maps/city_5.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_5::~city_5()
{

}
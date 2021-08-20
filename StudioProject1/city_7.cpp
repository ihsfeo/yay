#include "city_7.h"
#include "characters.h"
#include "non_trainer.h"

city_7::city_7()
{
	areaName = " City";
	setMap("./Area Maps/city_7.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_7::~city_7()
{

}
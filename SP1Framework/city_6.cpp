#include "city_6.h"
#include "characters.h"
#include "non_trainer.h"

city_6::city_6()
{
	areaName = " City";
	setMap("./Area Maps/city_6.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_6::~city_6()
{

}
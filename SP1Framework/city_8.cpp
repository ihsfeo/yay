#include "city_8.h"
#include "characters.h"
#include "non_trainer.h"

city_8::city_8()
{
	areaName = " City";
	setMap("./Area Maps/city_8.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_8::~city_8()
{

}
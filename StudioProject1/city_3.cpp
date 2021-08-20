#include "city_3.h"
#include "characters.h"
#include "non_trainer.h"

city_3::city_3()
{
	areaName = " City";
	setMap("./Area Maps/city_3.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_3::~city_3()
{

}
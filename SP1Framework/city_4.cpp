#include "city_4.h"
#include "characters.h"
#include "non_trainer.h"

city_4::city_4()
{
	areaName = " City";
	setMap("./Area Maps/city_4.txt");
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_4::~city_4()
{

}
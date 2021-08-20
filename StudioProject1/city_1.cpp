#include "city_1.h"
#include "characters.h"
#include "non_trainer.h"

city_1::city_1()
{
	areaName = "Neptune City";
	setMap("./Area Maps/city_1.txt"); //90(width)x31
	charactersPresent[0] = new non_trainer; //temporary eg
}

city_1::~city_1()
{

}
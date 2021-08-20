#include "gym_5.h"
#include "characters.h"
#include "trainer.h"

gym_5::gym_5()
{
	areaName = " City Gym";
	setMap("./Area Maps/gym_5.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 5;
}

gym_5::~gym_5()
{

}
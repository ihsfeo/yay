#include "gym_6.h"
#include "characters.h"
#include "trainer.h"

gym_6::gym_6()
{
	areaName = " City Gym";
	setMap("./Area Maps/gym_6.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 6;
}

gym_6::~gym_6()
{

}
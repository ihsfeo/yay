#include "gym_3.h"
#include "characters.h"
#include "trainer.h"

gym_3::gym_3()
{
	areaName = " City Gym";
	setMap("./Area Maps/gym_3.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 3;
}

gym_3::~gym_3()
{

}
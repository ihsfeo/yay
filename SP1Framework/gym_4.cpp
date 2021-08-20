#include "gym_4.h"
#include "characters.h"
#include "trainer.h"

gym_4::gym_4()
{
	areaName = " City Gym";
	setMap("./Area Maps/gym_4.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 4;
}

gym_4::~gym_4()
{

}
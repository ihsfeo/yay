#include "gym_2.h"
#include "characters.h"
#include "trainer.h"

gym_2::gym_2()
{
	areaName = "Venus City Gym"; //grass type
	setMap("./Area Maps/gym_2.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 2;
}

gym_2::~gym_2()
{

}
#include "gym_1.h"
#include "trainer.h"

gym_1::gym_1()
{
	areaName = "Neptune City Gym"; //water type
	setMap("./Area Maps/gym_1.txt");
	charactersPresent[0] = new trainer; //temporary eg, shouldb impt trainer
    badgeNo = 1;
}

gym_1::~gym_1()
{

}
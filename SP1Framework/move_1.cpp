#include "move_1.h"

move_1::move_1()
{
	setMoveName("Fireball");
	setMoveType('F'); //initialise temporary null
	setAtkType(atkType = 'S');
	setAtkPower(60);
	setStatusEffect('B');
	setStatEffProbability(70);
	setAccuracy(90);
}
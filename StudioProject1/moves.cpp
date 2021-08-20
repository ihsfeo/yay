#include "moves.h"

moves::moves()
{
	setMoveName("Null");
	setMoveType('N'); //initialise temporary null
	setAtkType(atkType = 'N');
	setAtkPower(0);
	setStatusEffect('N');
	setStatEffProbability(0);
	setAccuracy(0);
}

moves::~moves()
{

}

void moves::setMoveName(std::string name)
{
	moveName = name;
}

void moves::setMoveType(char type)
{
	moveType = type;
}

void moves::setAtkType(char aType) //Sp of Phys
{
	atkType = aType;
}

void moves::setAtkPower(int power)
{
	atkPower = power;
}

void moves::setStatusEffect(char statusE)
{
	statusEffect = statusE;
}

void moves::setStatEffProbability(int prob)
{
	statEffProbability = prob;
}

void moves::setAccuracy(int accuracy)
{
	this->accuracy = accuracy;
}

std::string moves::getMoveName(void)
{
	return moveName;
}


char moves::getMoveType(void)
{
	return moveType;
}

char moves::getAtkType(void)
{
	return atkType;
}

int moves::getAtkPower(void)
{
	return atkPower;
}

char moves::getStatusEffect(void)
{
	return statusEffect;
}

int moves::getStatEffProbability(void)
{
	return statEffProbability;
}

int moves::getAccuracy(void)
{
	return accuracy;
}
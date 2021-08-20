#pragma once
#include <string>

class moves
{
protected:
	std::string moveName;
	char moveType; //eg F? W?
	char atkType; //Special or Physical?
	int atkPower; 
	char statusEffect; //N - null, S - sleep, P - poison, B - burn
	int statEffProbability; //accuracy of status ailment affliction (eg this move got 80% chance to put target to sleep)
	int accuracy; //accuracy of the move itself, if it will hit the target at all

public:
	moves();
	~moves();
	void setMoveName(std::string name);
	void setMoveType(char type);
	void setAtkType(char aType);
	void setAtkPower(int power);
	void setStatusEffect(char statusE);
	void setStatEffProbability(int prob);
	void setAccuracy(int accuracy);

	std::string getMoveName(void);
	char getMoveType(void);
	char getAtkType(void);
	int getAtkPower(void);
	char getStatusEffect(void);
	int getStatEffProbability(void);
	int getAccuracy(void);
};


#pragma once
#include "area.h"
#include "trainer.h" //later change to important trainer

class gym : public area
{
protected:
    int badgeNo; //which number badge it is. the more you progress, 
                //the higher the number

public:
    gym();
    virtual ~gym();
    int getBadgeNo(void); //used for asciidex to know what badges to show
};
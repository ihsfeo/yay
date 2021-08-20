#include"asciimondesign.h"
int num;

asciimondesign::asciimondesign()
{
    switch (num)
    {
    case 1:
	asciimonname = "Tankman";
	setdesign("./asciimon designs/tankman.txt"); //Tankman ascii art
    break;

    case 2:
    asciimonname = "Titark";
	setdesign("./asciimon designs/titark.txt"); //Titark ascii art
    break;
    
    case 3:
    asciimonname = "Stompadon";
	setdesign("./asciimon designs/stompadon.txt"); //Stompadon ascii art
    break;
    
    case 4:
    asciimonname = "Spuster";
	setdesign("./asciimon designs/spuster.txt"); //Spuster ascii art
    break;
	
    case 5:
    asciimonname = "Spomb";
	setdesign("./asciimon designs/spomb.txt"); //Spomb ascii art
    break;

    case 6:
    asciimonname = "Snattle";
	setdesign("./asciimon designs/snattle.txt"); //Snattle ascii art
    break;

    case 7:
	asciimonname = "Slumberlumber";
	setdesign("./asciimon designs/slumberlumber.txt"); //Slumberlumber ascii art
    break;
    
    case 8:
	asciimonname = "Shrimp king";
	setdesign("./asciimon designs/shrimp king.txt"); //Shrimp king ascii art
    break;

    case 9:
	asciimonname = "Onrefni";
	setdesign("./asciimon designs/onrefni.txt"); //Onrefni ascii art
    break;

    case 10:
    asciimonname = "Lazyweed";
	setdesign("./asciimon designs/lazyweed.txt"); //Lazyweed ascii art
    break;

    case 11:
	asciimonname = "Erif";
	setdesign("./asciimon designs/erif.txt"); //Erif ascii art
    break;

    case 12:
	asciimonname = "Cratorgator";
	setdesign("./asciimon designs/cratorgator.txt"); //Cratorgator ascii art
    break;

    case 13:
    asciimonname = "Carniseed";
	setdesign("./asciimon designs/carniseed.txt"); //Carniseed ascii art
    break;

    case 14:
	asciimonname = "Beezmomon";
	setdesign("./asciimon designs/beezmomon.txt"); //Beezmomon ascii art
    break;

    case 15:
	asciimonname = "Anchorler";
	setdesign("./asciimon designs/anchorler.txt"); //Anchorler ascii art
    break;
    }
}


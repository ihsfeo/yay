#pragma once
#include "characters.h"
#include "position.h"
#include <string>

class area
{
protected:
	//char areaMap[50][110]; //store appearance of area
	std::string* areaMap; //store appearance of area
	characters* charactersPresent[10]; //store list of trainers in an area, doesn't include the player
	//need to know max number of trainers we're going to have per area
	int width;
	int height;
	std::string areaName;
	void setMap(std::string filename);

public:
	area(); //hardcodes the areaMap and trainersPresent (in derived classes)
	virtual ~area();
	char  readMap(int row, int col); //returns char on map for specific position
	std::string readMap(int row, int startcol, int endcol); //returns a string on map for specific range
	void setWidth(int width);
	void setHeight(int height);
	int getWidth(void);
	int getHeight(void);
	std::string getAreaName(void);
	static int randomiser(int minRange, int maxRange); //randomiser can be used for asciimon 
								//encounter and use of healing items in gym

	// may want to move to another class for others to use
	/* Function: loadData
	** filename - name of the file to read from (if running from Visual Studio, relative path is {project path}\{project name})
	** dataBuffer - address of the array of string
	**
	** allocates memory for array of string, dataBuffer, and fills it with content of file {filename}
	** returns the number of string in the array
	** returns 0 if unable to open file or no content in file read
	*/
	static int loadData(std::string filename, std::string** dataBuffer);
};


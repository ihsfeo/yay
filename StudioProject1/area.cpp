#include "area.h"
#include "string.h"
#include <iostream>
#include <fstream>      // std::ifstream

using namespace std;

area::area()
{
	areaName = "null"; //temporary void
	srand(rand() ^ (unsigned int)time(NULL)); //used for better randomisation (since rand isn't very random) uses your time to generate random seed to get rand no
	setMap("./Area Maps/areaMapTest.txt");
    for (int i = 0; i < 10; i++)
    {
        charactersPresent[i] = nullptr; //initialising charactersPresent
    }
}

area::~area()
{
    delete areaMap;
    for (int i = 0; i < 10; i++)
    {
        if (charactersPresent[i] != nullptr)
        {
            delete charactersPresent[i];
        }
    }
}

void area::setMap(string filename) //pass in a file name, avoid hardcode
{
    /*use text file later, now hardcode string array
    ifstream inputFile;
    inputFile.open("areaMapTest.txt");

    // Skip newline after the number of columns
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // And the empty line after that
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int row = 0; row < 50; row++)
    {
        for (int col = 0; col < 110; col++)
        {
        inputFile >> areaMap[row][col];
        }
    }

    /*for (int row = 0; row < 50; row++) //////////////TO TEST PRINT
    {
        for (int col = 0; col < 110; col++)
        {
            cout << areaMap[row][col];
        }
        //inputFile.get();
        cout << endl;
    }
    string mapData[20] = {
"XXXXXXXXXXXXXXXXXXXX",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X        T         X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"X                  X",
"XXXXXXXXXXXXXXXXXXXX" };
    int dataIdx = 0;
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 20; col++)
        {
            areaMap[row] = mapData[dataIdx++];
        }
    }*/

    int w = 0, minw = 0, h;
    h = loadData(filename, &areaMap);
    setHeight(h);

    //sets the width as the minimum length of strings in areaMap (in case not all string in array of same length)
    if (h > 0)
    {
        for (int i = 0; i < h; i++)
        {
            w = areaMap[i].size(); //set w as width of first string element in array
            if (i == 0)
            {
                minw = w;
            }
            else if (w < minw) //if current w is smaller than min
            {
                minw = w; //change min to this new w
            }
        }
    }
    setWidth(minw);
}

/* Function: loadData
** filename - name of the file to read from (if running from Visual Studio, relative path is {project path}\{project name})
** dataBuffer - address of the array of string
**
** allocates memory for array of string, dataBuffer, and fills it with content of file {filename}
** returns the number of string in the array
** returns 0 if unable to open file or no content in file read
*/
int area::loadData(string filename, string** dataBuffer)
{
    ifstream inputFile; //need use ifstream to read file
    int row = 0, maxrow = 0;
    string line;

    inputFile.open(filename, ios::in); //opening the file for reading only
    if (!inputFile)
    {
        cerr << "Error: file [" << filename << "] could not be opened" << endl;
    }
    else
    {
        //count number of lines in the file
        while (!inputFile.eof()) //while end of file is false
        {
            getline(inputFile, line); //put one row in file into the line string
                                    //after this reading, bool eof is updated
            maxrow++;
        }

        if (maxrow > 0) //in case file is empty/cannot be read
        {
            *dataBuffer = new string[maxrow]; //dynamically allocate dataBuffer array

            inputFile.seekg(ios_base::beg); //goes back to beginning of file to read line by line into the array

            while (!inputFile.eof())
            {
                getline(inputFile, (*dataBuffer)[row++]);
            }
        }
        else
        {
            cerr << "Error: file [" << filename << "] has no data" << endl;
        }
        inputFile.close(); //close the file so people can write into it
    } //file opened successfully

    return maxrow;
}

char area::readMap(int row, int col)
{
	return (areaMap[row][col]);
}

std::string area::readMap(int row, int startcol, int endcol)
{
    /*
    std::string storage = "";
    for (int i = startcol; i < (endcol-startcol); i++)
	{
		storage += areaMap[row][i];
	}
    
	return storage;
    */
    return areaMap[row].substr(startcol, (endcol - startcol + 1));
    
}

void area::setWidth(int width)
{
	this->width = width;
}

void area::setHeight(int height)
{
	this->height = height;
}

int area::getWidth(void)
{
	return width;
}

int area::getHeight(void)
{
	return height;
}

std::string area::getAreaName(void)
{
	return areaName;
}

int area::randomiser(int minRange, int maxRange)
{
	int rnd = 0;
	rnd = rand() % maxRange + minRange; //random number from min number 
										//to max number, including min and 
										//max number
	return rnd;
}
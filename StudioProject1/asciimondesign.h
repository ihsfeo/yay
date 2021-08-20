#pragma once
#include <string>
class asciimondesign
{
protected:
	int width;
	int height;
	std::string asciimonname;
	void setdesign(std::string filename);

public:
    asciimondesign();
    ~asciimondesign();
};
#include "GameScriptFileDatasetKeynameChildren.h"

GameScriptFileDatasetKeynameChildren::GameScriptFileDatasetKeynameChildren(string line)
{
	//line = 'key1:"data"'
	unsigned posofcolin = line.find(":");
	nameofdata = line.substr(0,posofcolin);
	line = line.substr(posofcolin +2);
	thedata = line;
}

string GameScriptFileDatasetKeynameChildren::getDataName()
{
	return nameofdata;
}

string GameScriptFileDatasetKeynameChildren::getDataValue()
{
	return thedata;
}

GameScriptFileDatasetKeynameChildren::~GameScriptFileDatasetKeynameChildren(void)
{
}

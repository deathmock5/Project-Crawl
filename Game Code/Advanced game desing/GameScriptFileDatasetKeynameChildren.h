#pragma once
#ifndef _GameScriptFileDatasetKeynameChildren_H_
#define _GameScriptFileDatasetKeynameChildren_H_

using namespace std;
#include <iostream>
#include <vector>

class GameScriptFileDatasetKeynameChildren
{
public:
	GameScriptFileDatasetKeynameChildren();
	GameScriptFileDatasetKeynameChildren(string line); //nameofme:data
	string getDataName();
	string getDataValue();
	~GameScriptFileDatasetKeynameChildren(void);
private:
	string nameofdata;
	string thedata;
};
#endif
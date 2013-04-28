#pragma once
#ifndef _GameScriptFileDatasetKeyname_H_
#define _GameScriptFileDatasetKeyname_H_
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include "SystemVars.h"
#include "GameScriptFileDatasetKeynameChildren.h"

class GameScriptFileDatasetKeyname
{
public:
	GameScriptFileDatasetKeyname(string lines); //parrent:info{child:info,child:info}
	string getMyName();
	string getMyDatafire();
	LINETYPE getLineType();
	LINETYPE getLineType(string line);
	vector<GameScriptFileDatasetKeynameChildren> getChildData();
	~GameScriptFileDatasetKeyname(void);
private:
	const bool hasdatamembers;
	string myname;
	string mydatafire;
	int numbofchildren;
	LINETYPE mylinetype;
	vector<GameScriptFileDatasetKeynameChildren> children;
};
#endif
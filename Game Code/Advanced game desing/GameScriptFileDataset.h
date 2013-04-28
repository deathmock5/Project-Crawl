#pragma once
#include <locale>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include "GameScriptFileDatasetKeyname.h"
class GameScriptFileDataset
{
public:
	GameScriptFileDataset(std::ifstream& inputfile);
	int getNumberOfRecords();
	std::vector<GameScriptFileDatasetKeyname> getDatasets();
	~GameScriptFileDataset(void);
private:
	std::vector<GameScriptFileDatasetKeyname> data;
	int amountofrecords;
};

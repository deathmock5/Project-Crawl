#include "GameScriptFileDataset.h"

GameScriptFileDataset::GameScriptFileDataset(std::ifstream& inputfile)
{
	try
	{
	char singlechar;
	string builtstr = "";
	bool inacomment = false;
	amountofrecords = 0;
	singlechar = inputfile.get();
	while(!inputfile.eof())
	{
		if(singlechar == '/' && inputfile.peek() == '/')
		{
			inacomment = true;//we started to be in a comment.
		}
		else if(!inacomment && singlechar != '}')
		{
			if(singlechar != '\n')
			{
				builtstr = std::string(builtstr) + singlechar;//were not in a comment
			}
		}
		else if(inacomment)
		{
			if(singlechar == '\n')
			{
				inacomment = false; //we stoped being in a comment.
			}
		}
		else
		{
			//its a '}'
			builtstr = std::string(builtstr) + '}'; // add it
			GameScriptFileDatasetKeyname newsetkey(builtstr);
			data.push_back(newsetkey);
			builtstr = "";
			amountofrecords++;
		}
		singlechar = inputfile.get();
	}
	}
	catch(...)
	{
		logHelperMessage(SEVERE,3,"File:'",myconcat(2,inputfile.getloc().c_str(),"' FAILED to parse."));
	}
}

int GameScriptFileDataset::getNumberOfRecords()
{
	return amountofrecords;
}

std::vector<GameScriptFileDatasetKeyname> GameScriptFileDataset::getDatasets()
{
	return data;
}

GameScriptFileDataset::~GameScriptFileDataset(void)
{

}

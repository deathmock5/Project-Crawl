#include "GameScriptFileDatasetKeyname.h"

GameScriptFileDatasetKeyname::GameScriptFileDatasetKeyname(string lines):hasdatamembers(true)
{
	//lines = 'parrent:info{	child:info,	child:info}'
	unsigned posiofcolin = lines.find(":");
	myname = lines.substr(0,(int)posiofcolin);
	mylinetype = LINETYPE_UNKNOWN;
	mylinetype = getLineType(myname);
	unsigned positionofbracket = lines.find("{");
	mydatafire = lines.substr(posiofcolin + 1,positionofbracket - posiofcolin - 1);
	//clear unessisary information
	lines = lines.substr(positionofbracket + 1); //erase data upto first bracket
	lines = lines.substr(0,lines.length() - 1); // and remove end bracket
	//we should be left with:'	child:info,	child:info'
	numbofchildren = std::count(lines.begin(),lines.end(),'"') / 2;
	for(int i = 0; i < numbofchildren; i++)
	{
		bool isclean = false;
		while (!isclean)
		{
			if(lines[0] == ' ' || lines[0] == '\t' )
			{
				//erase the char
				lines = lines.substr(1);
			}
			else
			{
				isclean = true;
			}
		}
		bool foundnextchild = false;
		bool inquotes = false;
		int indexcount = 0;
		while(!foundnextchild && indexcount < lines.length())
		{
			if(lines[indexcount] == '"' && !inquotes)
			{
				inquotes = true;
			}
			else if(lines[indexcount] == '"' && inquotes)
			{
				inquotes = false;
			}
			if(!inquotes)
			{
				if(lines[indexcount] == ',')
				{
					foundnextchild = true;
				}
			}
			indexcount++;
		}
		GameScriptFileDatasetKeynameChildren newchild(lines.substr(0,indexcount-1));
		children.push_back(newchild);
		if(foundnextchild)
		{
			lines = lines.substr(indexcount + 1);
		}
	}
}

GameScriptFileDatasetKeyname::~GameScriptFileDatasetKeyname(void)
{

}

string GameScriptFileDatasetKeyname::getMyName()
{
	return myname;
}

string GameScriptFileDatasetKeyname::getMyDatafire()
{
	return mydatafire;
}

vector<GameScriptFileDatasetKeynameChildren> GameScriptFileDatasetKeyname::getChildData()
{
	return children;
}

LINETYPE GameScriptFileDatasetKeyname::getLineType()
{
	return mylinetype;
}

LINETYPE GameScriptFileDatasetKeyname::getLineType(string line)
{
	if(mylinetype == LINETYPE_UNKNOWN)
	{
		std::transform(line.begin(), line.end(), line.begin(), ::tolower); //Make all lower case.
		if(line.find("dialog")!=std::string::npos)
		{
			return LINETYPE_DIALOG;
		}
		if(line.find("spawnentity")!=std::string::npos)
		{
			return LINETYPE_SPAWNENTITY;
		}
		if(line.find("changelightlevel")!=std::string::npos)
		{
			return LINETYPE_CHANGELIGHTLEVEL;
		}
		if(line.find("spawntorch")!=std::string::npos)
		{
			return LINETYPE_SPAWNTORCH;
		}
		if(line.find("spawngold")!=std::string::npos)
		{
			return LINETYPE_SPAWNGOLD;
		}
		if(line.find("playsfx")!=std::string::npos)
		{
			return LINETYPE_PLAYSFX;
		}
		if(line.find("moveplayer")!=std::string::npos)
		{
			return LINETYPE_MOVEPLAYER;
		}
		if(line.find("onroomenter")!=std::string::npos)
		{
			return LINETYPE_ONROOMENTER;
		}
		if(line.find("warptomap")!=std::string::npos)
		{
			return LINETYPE_WARPTOMAP;
		}
		if(line.find("//")!=std::string::npos)
		{
			return LINETYPE_COMMENT;
		}
		return LINETYPE_UNKNOWN; //well. it cant be anything usefull, ignore it.
	}
	else
	{
		return mylinetype;
	}
}

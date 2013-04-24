#include "EventManager.h"
#include "GameEventChangeLightLevel.h"
#include "GameEventDialog.h"
#include "GameEventMovePlayer.h"
#include "GameEventOnRoomEnter.h"
#include "GameEventPlaySfx.h"
#include "GameEventSpawnEntity.h"
#include "GameEventSpawnGold.h"
#include "GameEventSpawnTorch.h"
#include "GameEventWarpToMap.h"

EventManager::EventManager(void)
{

}
EventManager::~EventManager(void)
{

}
bool EventManager::tickUpdate()
{
	return false;
	//TODO: return true if theres an event to process.
	//int curentmanagedevent = theeventid
}
void EventManager::eventProcess(Dungion&,Menu&)
{
	//TODO: ok. i have a ref to the dung and to the menu, lets make things hapen.
	//what event is suposed to pop?

}
bool EventManager::isEventInProcess()
{
	//TODO: if curentmanagedevent == -1
	return false;
	
}
void EventManager::loadEvents(string file)
{
	ifstream scriptfile;
	scriptfile.open(myconcat(2,"Scripts\\",file.c_str()));
	
    if(!scriptfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myconcat(2,"Scripts\\",file.c_str()).c_str(),"' open.");
		char next = '\n';								//set endline charicter
		string line;									//set blank line
		LINETYPE linetype;								//determine the line type
		scriptfile.get(next);							//get garbage data out
		scriptfile.get(next);
		scriptfile.get(next);
		getline(scriptfile,line);						//input the first line
		while(!scriptfile.eof())						//while te files open
		{
			linetype = getLineType(line.c_str());				//get the line type.
			GameEvent newevent;
			string arguments[8];
			if(linetype != LINETYPE_COMMENT)            //comments are ignored.
				{
				arguments[0] = line;					//get the linetype:identifier line
				int incrimenter = 1;					//start inctimenting at one.
				getline(scriptfile,line);				//get the next line.
				while(line.find("}")==std::string::npos)//loop untill you find the closeing curly brace.
				{
					arguments[incrimenter++] = line;	//add each line.
					getline(scriptfile,line);			//get the next line.
				}
			}
			
			switch (linetype)
			{
			case LINETYPE_COMMENT:
				//IGNORE MEEEEE
				break;
			case LINETYPE_DIALOG:
				newevent = GameEventDialog();			//Lets add a new dialog
				//if(is_number(getLineValue(arguments[0])))
				//{
				//	//ok its timed
				//	arguments[0] = getLineValue(arguments[0]);
				//}
				//else
				//{
				//	//arguments[0] = -1;																	//dialog:#
				//	//arguments[1] = getLineValue(arguments[0]);											//dialog:foo
				//}
				////arguments[2] = getLineValue(arguments[2]);												//	Face:""
				////arguments[3] = getLineValue(arguments[3]);												//	Text:""
				//if(arguments[4] != "")
				//{
				//	//i trigger another event
				//	arguments[4] = getLineValue(arguments[4]);
				//}
				//newevent.setEventPramiters(2,1,1);      //add the dialog information to the thing
				/*mytimedactivator = va_arg(messages,int);
				faceimg = load_image(myconcat(2,"\\Images\\Faces\\",va_arg(messages,string)));
				text = va_arg(messages,string);
				if(number > 3)
				{
					myidentactivator = va_arg(messages,string);
				}*/
				break;
			case LINETYPE_SPAWNENTITY:
				break;
			case LINETYPE_CHANGELIGHTLEVEL:
				break;
			case LINETYPE_SPAWNTORCH:
				break;
			case LINETYPE_SPAWNGOLD:
				break;
			case LINETYPE_PLAYSFX:
				break;
			case LINETYPE_MOVEPLAYER:
				break;
			case LINETYPE_ONROOMENTER:
				break;
			case LINETYPE_WARPTOMAP:
				break;
			case LINETYPE_UNKNOWN:
				break;
			default:
				break;
			}
			getline(scriptfile,line);			//get the next line.
			if(linetype != LINETYPE_COMMENT)
			{
				gamevents.push_back(newevent);
			}
		}
        string filetileset;
		string filebgs;
		string filenumrooms;
		string filemon1;
		string filemon2;
		string fileboss;
		scriptfile.close();//close file
	}
    else
    {
		logHelperMessage(SEVERE,3,"File:'",myconcat(2,"Scripts\\",file.c_str()).c_str(),"' FAILED.");
        //cout << "Unable to open file:" << myfile << endl;
    }
}
void EventManager::addDialogEvent(int time)
{
	//TODO: add a dialog event to the stack.
}
void EventManager::addDIilogEvent(string uniqeid)
{
	//TODO: add a dialog event by uniqueid
}
void EventManager::addEntitySpawnEvent(int time)
{

}
void EventManager::addEntitySpawnEvent(string uniqueid)
{}
void EventManager::addLightChangeEvent(int time)
{}
void EventManager::addLightChangeEvent(string uniqueid)
{}
void EventManager::addSpawnTorchEvent(int time)
{}
void EventManager::addSpawnTorchEvent(string uniqueid)
{}
void EventManager::addSpawnGoldEvent(int time)
{}
void EventManager::addSpawnGoldEvent(string uniqueid)
{}
void EventManager::addPlaySfxEvent(int time)
{}
void EventManager::addPlaySfxEvent(string uniqueid)
{}
void EventManager::addMovePlayerEvent(int time)
{}
void EventManager::addMovePlayerEvent(string uniqueid)
{}
void EventManager::addRoomEnterEvent(string roomid)
{}
void EventManager::addWarpToMapEvent(int time)
{}
void EventManager::addWarpToMapEvent(string uniqueid)
{}
LINETYPE EventManager::getLineType(string line)
{
	std::transform(line.begin(), line.end(), line.begin(), ::tolower); //Make all lower case.
	if(line.find("dialog:")!=std::string::npos)
	{
		return LINETYPE_DIALOG;
	}
	if(line.find("spawnentity:")!=std::string::npos)
	{
		return LINETYPE_SPAWNENTITY;
	}
	if(line.find("changelightlevel:")!=std::string::npos)
	{
		return LINETYPE_CHANGELIGHTLEVEL;
	}
	if(line.find("spawntorch:")!=std::string::npos)
	{
		return LINETYPE_SPAWNTORCH;
	}
	if(line.find("spawngold:")!=std::string::npos)
	{
		return LINETYPE_SPAWNGOLD;
	}
	if(line.find("playsfx:")!=std::string::npos)
	{
		return LINETYPE_PLAYSFX;
	}
	if(line.find("moveplayer:")!=std::string::npos)
	{
		return LINETYPE_MOVEPLAYER;
	}
	if(line.find("onroomenter:")!=std::string::npos)
	{
		return LINETYPE_ONROOMENTER;
	}
	if(line.find("warptomap:")!=std::string::npos)
	{
		return LINETYPE_WARPTOMAP;
	}
	if(line.find("//")!=std::string::npos)
	{
		return LINETYPE_COMMENT;
	}
	logHelperMessage(WARNING,3,"Line: '",line.c_str(),"' Not determinable.");
	return LINETYPE_UNKNOWN; //well. it cant be anything usefull, ignore it.
}
string EventManager::getLineValue(string data)
{
	return data.substr(data.find(":")+1);
}
bool EventManager::is_number(const std::string& s)
{
	bool hasfound = false;
	locale loc ( "en_US" );
	for(int i = 0; i < s.length();i++)
	{
		if(std::isdigit(s[i],loc))
		{
			hasfound = true;
			i = s.length();
		}
	}
	return hasfound;
}
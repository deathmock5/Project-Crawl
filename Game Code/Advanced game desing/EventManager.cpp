#include "EventManager.h"


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
	scriptfile.open(myconcat(3,"Scripts\\",file.c_str(),".dngsc"));
	
    if(!scriptfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myconcat(3,"Scripts\\",file.c_str(),".dngsc").c_str(),"' open.");
		char next = '\n';
		string line;
		LINETYPE linetype;
		scriptfile >> line;
		while(!scriptfile.eof())
		{
			linetype = getLineType(line);
			GameEvent newevent;
			string arguments[8];
			if(linetype != LINETYPE_COMMENT)            //comments are ignored.
				{
				arguments[0] = line;					//get the linetype:identifier line
				int incrimenter = 1;					//start inctimenting at one.
				while(!line.find("}"))					//loop untill you find the closeing curly brace.
				{
					arguments[incrimenter++] = line;	//add each line.
					scriptfile >> line;					//get the next line.
				}
				scriptfile >> line;
			}
			switch (linetype)
			{
			case LINETYPE_COMMENT:
				//IGNORE MEEEEE
				break;
			case LINETYPE_DIALOG:
				newevent = GameEventDialog();			//Lets add a new dialog
				arguments[0];							//Dialog:activator
				arguments[1];							//{
				arguments[2];							//	Face:""
				arguments[3];							//	Text:""
				arguments[4];   						//	Identifier:?
				arguments[5];							//}
				newevent.setEventPramiters(2,1,1);      //add the dialog information to the thing
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
			scriptfile >> line;
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
		logHelperMessage(SEVERE,3,"File:'",myconcat(3,"Scripts\\",file.c_str(),".dngsc").c_str(),"' FAILED.");
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
LINETYPE EventManager::getLineType(string)
{
	//TODO: um, somshit here.
	return LINETYPE_DIALOG;
}
string EventManager::getLineValue(string data)
{
	data = data.substr(':');

	return data;
}
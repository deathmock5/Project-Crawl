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
			switch (linetype)
			{
			case LINETYPE_COMMENT:
				//IGNORE MEEEEE
				break;
			case LINETYPE_DIALOG:
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
		}
        string filetileset;
		string filebgs;
		string filenumrooms;
		string filemon1;
		string filemon2;
		string fileboss;
		scriptfile.get(next);

		scriptfile >> filetileset;
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
	return LINETYPE_CHANGELIGHTLEVEL;
}
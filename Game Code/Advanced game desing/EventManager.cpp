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
void EventManager::eventProcess()
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
	GameEvent newevent;
	scriptfile.open(myconcat(2,"Scripts\\",file.c_str()));
    if(!scriptfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myconcat(2,"Scripts\\",file.c_str()).c_str(),"' open.");

		GameScriptFileDataset mydataset(scriptfile);
		vector<GameScriptFileDatasetKeyname> records = mydataset.getDatasets();
			for(int i = 0;i < records.size();i++)
			{
				vector<GameScriptFileDatasetKeynameChildren> recordsofchildren;
				string value;
				string arguments[8];
				//0 # activator
				//1 string activator
				//2-6 args
				//7 identifier
				switch (records[i].getLineType())
				{
				case LINETYPE_COMMENT:
					//IGNORE MEEEEE
					break;
				case LINETYPE_DIALOG:
					newevent = GameEventDialog();																//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//dialog:#
							arguments[1] = "null";																	//dialog:foo
						}
						else
						{
							arguments[0] = -1;																		//dialog:#
							arguments[1] = value;																	//dialog:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//Face:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//Text:"blablabla"
						if(recordsofchildren.size() > 2)
						{
							arguments[7] = recordsofchildren[2].getDataValue();										//identifer:"thing"
							newevent.setEventPramiters(4,arguments[0],arguments[1],arguments[2],arguments[3]);
						}
						else
						{
							newevent.setEventPramiters(5,arguments[0],arguments[1],arguments[2],arguments[3],arguments[7]);	
						}
						//add the dialog information to the thing
						logHelperMessage(INFO,3,"---DIALOG:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---DIALOG:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					break;
				case LINETYPE_SPAWNENTITY:
					logHelperMessage(INFO,3,"---SPAWNENTITY:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_CHANGELIGHTLEVEL:
					logHelperMessage(INFO,3,"---CHANGELIGHTLEVEL:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_SPAWNTORCH:
					logHelperMessage(INFO,3,"---SPAWNTORCH:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_SPAWNGOLD:
					logHelperMessage(INFO,3,"---SPAWNGOLD:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_PLAYSFX:
					logHelperMessage(INFO,3,"---PLAYSFX:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_MOVEPLAYER:
					logHelperMessage(INFO,3,"---MOVEPLAYER:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_ONROOMENTER:
					logHelperMessage(INFO,3,"---ONROOMENTER:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_WARPTOMAP:
					logHelperMessage(INFO,3,"---WARPTOMAP:'",records[i].getMyDatafire().c_str(),"' found and created.");
					break;
				case LINETYPE_UNKNOWN:
					logHelperMessage(WARNING,3,"---UNKNOWN:'",records[i].getMyDatafire().c_str(),"' found.");
					break;
				default:
					logHelperMessage(WARNING,3,"---ERROR:'",records[i].getMyDatafire().c_str(),"' found.");
					break;
				}
		}
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
bool EventManager::is_number(const std::string& s)
{
	bool hasfound = false;
	locale loc ("C");
	for(int i = 0; i < s.length();i++)
	{
		if(std::isdigit(s[i],loc))
		{
			hasfound = true;
			i = s.length();
		}
	}
	return !hasfound;
}
#include "EventManager.h"
using namespace std;

EventManager::EventManager() : GameObject(CLASSTYPE_EVENTMANAGER)
{
	curenttimer = 1;
}
EventManager::~EventManager(void)
{

}
bool EventManager::tickUpdate()
{
	for(int i = 0;i < (int)gamevents.size();i++)
	{
		if(gamevents[i]->getMyTimedActivator() == curenttimer)
		{
			popedevents.push_back(i);
			return true;
		}
	}
	curenttimer++;
	return false;
}
void EventManager::eventProcess()
{
	//what event is suposed to pop?
	//logHelperMessage(INFO,1,"POPED");
	GameEvent* ev = gamevents[popedevents[0]];
	gamevents.erase(gamevents.begin() + popedevents[0]);
	popedevents.erase(popedevents.begin() + 0);
	(ev)->applyEvent();
}
bool EventManager::isEventInProcess()
{
	if(popedevents.size() > 0)
	{
		return true;
	}
	return false;
}
void EventManager::loadEvents(string file)
{
	ifstream scriptfile;
	GameEvent* newevent;
	scriptfile.open(myconcat(2,"Scripts\\",file.c_str()));
    if(!scriptfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myconcat(2,"Scripts\\",file.c_str()).c_str(),"' open.");

		GameScriptFileDataset mydataset(scriptfile);
		vector<GameScriptFileDatasetKeyname> records = mydataset.getDatasets();
			for(int i = 0;i < (int)records.size();i++)
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
					newevent = new GameEventDialog();																//Lets add a new dialog
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
							arguments[0] = "-1";																	//dialog:#
							arguments[1] = value;																	//dialog:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//Face:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//Text:"blablabla"
						if(recordsofchildren.size() == 3)
						{
							arguments[7] = recordsofchildren[2].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";
						}
						newevent->setEventPramiters(5,arguments[0],arguments[1],arguments[2],arguments[3],arguments[7]);
						//add the dialog information to the thing
						logHelperMessage(INFO,3,"---DIALOG:'",records[i].getMyDatafire().c_str(),"' found and created.");
						gamevents.push_back(newevent);
						}
					else
					{
						logHelperMessage(INFO,3,"---DIALOG:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_SPAWNENTITY:
					newevent = new GameEventSpawnEntity();															//Lets add a new entity
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																	//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//x:"blablabla"
						arguments[4] = recordsofchildren[2].getDataValue();											//y:"blablabla"
						if(recordsofchildren.size() == 4)
						{
							arguments[7] = recordsofchildren[3].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(6,arguments[0],arguments[1],arguments[2],arguments[3],arguments[4],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---SPAWNENTITY:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---SPAWNENTITY:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					
					break;
				case LINETYPE_CHANGELIGHTLEVEL:
					newevent = new GameEventChangeLightLevel();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						if(recordsofchildren.size() == 2)
						{
							arguments[7] = recordsofchildren[1].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(4,arguments[0],arguments[1],arguments[2],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---CHANGELIGHTLEVEL:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---CHANGELIGHTLEVEL:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_SPAWNTORCH:
					newevent = new GameEventSpawnTorch();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//x:"blablabla"									//y:"blablabla"
						if(recordsofchildren.size() == 3)
						{
							arguments[7] = recordsofchildren[2].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(5,arguments[0],arguments[1],arguments[2],arguments[3],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---SPAWNTORCH:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---SPAWNTORCH:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_SPAWNGOLD:
					newevent = new GameEventSpawnGold();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//x:"blablabla"
						arguments[4] = recordsofchildren[2].getDataValue();											//y:"blablabla"
						if(recordsofchildren.size() == 4)
						{
							arguments[7] = recordsofchildren[3].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(6,arguments[0],arguments[1],arguments[2],arguments[3],arguments[4],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---SPAWNGOLD:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---SPAWNGOLD:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_PLAYSFX:
					newevent = new GameEventPlaySfx();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						if(recordsofchildren.size() == 2)
						{
							arguments[7] = recordsofchildren[1].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(4,arguments[0],arguments[1],arguments[2],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---PLAYSFX::'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---PLAYSFX::'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_MOVEPLAYER:
					newevent = new GameEventMovePlayer();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 2)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[2] = recordsofchildren[0].getDataValue();											//File:"blablabla"
						arguments[3] = recordsofchildren[1].getDataValue();											//x:"blablabla"
						if(recordsofchildren.size() == 3)
						{
							arguments[7] = recordsofchildren[1].getDataValue();										//identifer:"thing"
						}
						else
						{
							arguments[7] = "null";	
						}
						newevent->setEventPramiters(5,arguments[0],arguments[1],arguments[2],arguments[3],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---MOVEPLAYER:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---MOVEPLAYER:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
					
					break;
				case LINETYPE_ONROOMENTER:
					newevent = new GameEventOnRoomEnter();															//Lets add a new dialog
					value = records[i].getMyDatafire();
					recordsofchildren = records[i].getChildData();
					if(records.size() >= 1)
					{
						if(is_number(value))
						{   																						//ok its timed
							arguments[0] = value;																	//spawn:#
							arguments[1] = "null";																	//spawn:foo
						}
						else
						{
							arguments[0] = "-1";																		//spawn:#
							arguments[1] = value;																	//spawn:foo
						}
						arguments[7] = recordsofchildren[0].getDataValue();										//identifer:"thing"
						newevent->setEventPramiters(3,arguments[0],arguments[1],arguments[7]);
						//add the dialog information to the thing
						gamevents.push_back(newevent);
						logHelperMessage(INFO,3,"---ONROOMENTER:'",records[i].getMyDatafire().c_str(),"' found and created.");
						}
					else
					{
						logHelperMessage(INFO,3,"---ONROOMENTER:'",records[i].getMyDatafire().c_str(),"' is invalid.");
					}
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
bool EventManager::is_number(const std::string& s)
{
	bool hasfound = false;
	locale loc ("C");
	for(int i = 0; i < (int)s.length();i++)
	{
		if(std::isdigit(s[i],loc))
		{
			
		}
		else
		{
			hasfound = true;
			i = s.length();
		}
	}
	return !hasfound;
}
void EventManager::sendMessage(string data)
{
	//logHelperMessage(INFO,2,"EM:",data.c_str());
	for(int i = 0;i < (int)gamevents.size();i++)
	{
		if(gamevents[i]->getMyIdentActivator() == data)
		{
			//logHelperMessage(INFO,2,"EM:Found",data.c_str());
			popedevents.push_back(i);
			eventProcess();
			return;
		}
		else
		{
			//logHelperMessage(INFO,2,"DG:",gamevents[i]->getMyIdentActivator().c_str());
		}
	}
}
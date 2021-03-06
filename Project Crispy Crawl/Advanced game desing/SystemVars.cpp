#include "SystemVars.h"

vector<string> dnglvs;
static Game* curentgame;
vector<loglevel> levels;
vector<string> messagess;
vector<ALLEGRO_BITMAP*> loadedbitmaps;
vector<string> loadedbitmapnames;
thread t1;
bool threaddone = true;
bool threadjoinedmain = true;
ALLEGRO_BITMAP* load_image(string path)
{
	ALLEGRO_BITMAP* file;
	int fileid = 0;
	for(int i = 0;i < loadedbitmapnames.size();i++)
	{
		if(loadedbitmapnames[i] == path)
		{
			try
			{
				file = al_load_bitmap(path.c_str());
				if(file == NULL)
					throw 1;
				logHelperMessage(OK,3,"The file:'",path.c_str(),"' loaded.");
				loadedbitmapnames.push_back(path);
			}
			catch(...)
			{
				logHelperMessage(SEVERE,3,"The file:'",path.c_str(),"' was not found.");
			}
			fileid = i;
			i = 99999;
		}
		else
		{
			logHelperMessage(OK,3,"The file:'",path.c_str(),"' is already loaded.");
		}
	}
	return file;
}
ALLEGRO_SAMPLE* load_sound(string path)
{
	ALLEGRO_SAMPLE* file;
	try
	{
		file = al_load_sample(path.c_str());
		if(file == NULL)
			throw 1;
		logHelperMessage(OK,3,"The file'",path.c_str(),"' loaded.");
	}
	catch(...)
	{
		logHelperMessage(SEVERE,3,"The file:'",path.c_str(),"' failed to load.");
	}
	return file;
}

void logHelperMessage(loglevel severity,int number, ...)
{
	//TODO: multithread this shit!
	//TODO: make it not need a number,
	//TODO: make it understand what argument it impoting
	va_list messages;
	va_start(messages,number);
	std::stringstream ss;

	for(int i = 0;i < number;i++)
	{
			ss << va_arg(messages,char*);
	}
	std::string s = ss.str();
	levels.push_back(severity);
	messagess.push_back(s);
	threadedloghelpermessage(severity,s);
}
void updateThreadQue()
{
	if(false)
	{
		if(threadjoinedmain == false)
		{
			t1.join();
			threadjoinedmain = true;
		}
		if(levels.size() > 0)
		{
			threaddone = false;
			threadjoinedmain = false;
			t1 = thread(threadedloghelpermessage,levels[0],messagess[0]);
			levels.erase(levels.begin());
			messagess.erase(messagess.begin());
		}
		
	}
}
void threadedloghelpermessage(loglevel severity,string message)
{
	//TODO: implement a stack.
	switch (severity)
	{
	case INFO:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
		cout << "[IF]";
		break;
	case WARNING:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x06);
		cout << "[WA]";
		break;
	case OK:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
		cout << "[OK]";
		break;
	case SEVERE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "[ER]";
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x08);
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t );
	cout << "[";
	int hour = now.tm_hour;
	if(hour < 10)
	{
		cout << 0 << hour << ":";
	}
	else
	{
		cout << hour << ":";
	}
	int minu = now.tm_min;
	if(minu < 10)
	{
		cout << 0 << minu << ":";
	}
	else
	{
		cout << minu << ":";
	}
	int sec = now.tm_sec;
	if(sec < 10)
	{
		cout << 0 << sec;
	}
	else
	{
		cout << sec;
	}
	cout << "] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
	cout << message << endl;
	threaddone = true;
}
//template <typename T>
//string NumberToString ( T Number )
//{
//	stringstream ss;
//	ss << Number;
//	return ss.str();
//	//string s = to_string((double)num);
//}
//template <typename T>
//T StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
//{										//character array as argument
//	stringstream ss(Text);
//	T result;
//	return ss >> result ? result : 0;
//}
void setGameRefrence(Game* mygame)
{
	curentgame = mygame;
}
Game* getGameRefrence()
{
	return curentgame;
}
string myconcat(string folder,string innerfolder,string filename)
{
	std::stringstream ss;
	ss << folder << innerfolder << filename;
	std::string s = ss.str();
	//cout << s << endl;
	return s;
}
string myconcat(int number,...)
{
	va_list messages;
	va_start(messages,number);
	std::stringstream ss;
	for(int i = 0;i < number;i++)
	{
		ss << va_arg(messages,char *);
	}
	std::string s = ss.str();
	return s;
}
string getrandommaplayout(bool bls)
{
	if(dnglvs.size() == 0)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;
		logHelperMessage(INFO,1,"No loaded .dnglv files found, populating list.");
		try
		{
			hFind = FindFirstFile("FloorLayouts\\*.dnglv", &FindFileData);
		}
		catch(...)
		{
			logHelperMessage(SEVERE,2,"Error:",GetLastError());
		}
		
		if (hFind == INVALID_HANDLE_VALUE) 
		{
			logHelperMessage(SEVERE,2,"Error:",GetLastError());
		} 
		else 
		{
			dnglvs.push_back(FindFileData.cFileName);
			logHelperMessage(OK,2,"Loaded dung layout:",FindFileData.cFileName);
			while (FindNextFile(hFind,&FindFileData))
			{
				logHelperMessage(OK,2,"Loaded dung layout:",FindFileData.cFileName);
				dnglvs.push_back(FindFileData.cFileName);
			}
			FindClose(hFind);
			logHelperMessage(INFO,1,".dnglv list populated sucsessfully");
		}
	}
	if(dnglvs.size() > 0)
	{
		int randomvar = rand() % (int)dnglvs.size();
		return dnglvs[randomvar];
	}
	return "null";
}
float getAngleToTarget(float x1,float y1,float x2,float y2)
{
	float deltax = x2 - x1;
	float deltay = y2 - y1;
	float angle = atan2(deltax,deltay);
	return angle - 3.14f / 2.0f;
}
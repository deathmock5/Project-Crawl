#include "SystemVars.h"
#ifndef _systemvars_cpp_
#define _systemvars_cpp_


vector<string> dnglvs;
ALLEGRO_BITMAP* load_image(string path)
{
	ALLEGRO_BITMAP* file;
	try
	{
		file = al_load_bitmap(path.c_str());
		//cout << "The file:'" << path.c_str() << "' loaded" << endl;
		if(file == NULL)
			throw 1;
		logHelperMessage(OK,3,"The file:'",path.c_str(),"' loaded.");
	}
	catch(...)
	{
		logHelperMessage(SEVERE,3,"The file:'",path.c_str(),"' was not found.");
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
	va_list messages;
	va_start(messages,number);
	std::stringstream ss;

	for(int i = 0;i < number;i++)
	{
			ss << va_arg(messages,char*);
	}
	std::string s = ss.str();
	thread t1(threadedloghelpermessage,severity,s);
	t1.join();
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
	struct tm * now = localtime( & t );
	cout << "[";
	int hour = now->tm_hour;
	if(hour < 10)
	{
		cout << 0 << hour << ":";
	}
	else
	{
		cout << hour << ":";
	}
	int minu = now->tm_min;
	if(minu < 10)
	{
		cout << 0 << minu << ":";
	}
	else
	{
		cout << minu << ":";
	}
	int sec = now->tm_sec;
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
		int randomvar = rand() % dnglvs.size() -1;
		return dnglvs[randomvar];
		//TODO: randomize a number and return fileinthefolder[n]
	}
	return "null";
}
#endif
#include "SystemVars.h"
#ifndef _systemvars_cpp_
#define _systemvars_cpp_



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
	va_list messages;
	va_start(messages,number);
	switch (severity)
	{
	case INFO:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
		cout << "[INFO]   ";
		break;
	case WARNING:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x06);
		cout << "[WARN]   ";
		break;
	case OK:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
		cout << "[OK]     ";
		break;
	case SEVERE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "[SEVERE] ";
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
	for(int i = 0;i < number;i++)
	{
			cout << va_arg(messages,char*);
	}
	cout << endl;
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
string getrandommaplayout(bool)
{
	return "thegame";
}
#endif
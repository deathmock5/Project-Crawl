// DMLogger.h

#pragma once
#ifndef _DMLOGGGER_
#define _DMLOGGGER_
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <ctime>
using namespace std;
#ifndef FOREGROUND_WHITE
#define FOREGROUND_WHITE 0x0007
#endif
#ifndef FOREGROUND_YELLOW
#define FOREGROUND_YELLOW 0x0006
#endif
#ifdef DMLOGGGER_EXPORTS
#define DMLOGGGER_API __declspec(dllimport) 
#else
#define DMLOGGGER_API __declspec(dllexport) 
#endif
namespace DMLogger {
	struct Log
	{
	  static Log& Info()
	  {
		static Log OutputThing;
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
		cout << "[IF]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		return OutputThing;
	  }
	  static Log& Ok()
	  {
		static Log OutputThing;
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
		cout << "[OK]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		return OutputThing;
	  }
	  static Log& Warn()
	  {
		static Log OutputThing;
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_YELLOW);
		cout << "[WA]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		return OutputThing;
	  }
	  static Log& Error()
	  {
		static Log OutputThing;
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "[ER]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		return OutputThing;
	  }

	  template< class T >
	  Log &operator<<( T val )
	  {
			if(0 == 0)
			{
				LogTimestamp();
				cout << val << endl;
				return *this;
			}
			else
			{
				/*logstream.open("nol", ios::app | ios::out);
				LogTimestamp(logstream);
				LogTimestamp();
				logstream << val << endl;
				cout << val << endl;
				logstream.close();*/
				return *this;
			}
	  }
	  
		private:
	  Log(){};
	  void LogTimestamp()
		{
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
	}
	  void LogTimestamp(ofstream& file)
		{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t );
		file << "[";
		int hour = now.tm_hour;
		if(hour < 10)
		{
			file << 0 << hour << ":";
		}
		else
		{
			file << hour << ":";
		}
		int minu = now.tm_min;
		if(minu < 10)
		{
			file << 0 << minu << ":";
		}
		else
		{
			file << minu << ":";
		}
		int sec = now.tm_sec;
		if(sec < 10)
		{
			file << 0 << sec;
		}
		else
		{
			file << sec;
		}
		file << "] ";
	}
	  //static ofstream logstream;
	};
}
#endif
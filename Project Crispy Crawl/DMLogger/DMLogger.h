// DMLogger.h

#pragma once
#ifndef _DMLOGGGER_
#define _DMLOGGGER_
#include <iostream>
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

	class Log
	{
	public:
		static DMLOGGGER_API void LogMessage(const char[512]);
		static DMLOGGGER_API void LogOk(const char[512]);
		static DMLOGGGER_API void LogWarn(const char[512]);
		static DMLOGGGER_API void LogError(const char[512]);
	private:
		//thread t1;
		static DMLOGGGER_API void LogTimestamp();
	};
	void Log::LogMessage(const char text[512])
	{
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
		cout << "[IF]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		LogTimestamp();
		cout << text << endl;
	}
	void Log::LogOk(const char text[512])
	{
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
		cout << "[OK]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		LogTimestamp();
		cout << text << endl;
	}
	void Log::LogWarn(const char text[512])
	{
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_YELLOW);
		cout << "[WA]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		LogTimestamp();
		cout << text << endl;
	}
	void Log::LogError(const char text[512])
	{
		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "[ER]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
		LogTimestamp();
		cout << text << endl;
	}
	void Log::LogTimestamp()
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
}
#endif
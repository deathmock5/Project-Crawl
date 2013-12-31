// This is the main DLL file.

#include "stdafx.h"
#include "DMLogger.h"
#include <stdexcept>

using namespace std;
//namespace DMLogger
//{
//	void Log::LogMessage(const char text[512])
//	{
//		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
//		cout << "[IF]";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
//		LogTimestamp();
//		cout << text << endl;
//	}
//	void Log::LogOk(const char text[512])
//	{
//		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
//		cout << "[OK]";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
//		LogTimestamp();
//		cout << text << endl;
//	}
//	void Log::LogWarn(const char text[512])
//	{
//		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_YELLOW);
//		cout << "[WA]";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
//		LogTimestamp();
//		cout << text << endl;
//	}
//	void Log::LogError(const char text[512])
//	{
//		SetStdHandle(STD_OUTPUT_HANDLE, GetStdHandle(STD_OUTPUT_HANDLE));
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
//		cout << "[ER]";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_WHITE);
//		LogTimestamp();
//		cout << text << endl;
//	}
//	void Log::LogTimestamp()
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x08);
//		time_t t = time(0);
//		struct tm now;
//		localtime_s(&now, &t );
//		cout << "[";
//		int hour = now.tm_hour;
//		if(hour < 10)
//		{
//			cout << 0 << hour << ":";
//		}
//		else
//		{
//			cout << hour << ":";
//		}
//		int minu = now.tm_min;
//		if(minu < 10)
//		{
//			cout << 0 << minu << ":";
//		}
//		else
//		{
//			cout << minu << ":";
//		}
//		int sec = now.tm_sec;
//		if(sec < 10)
//		{
//			cout << 0 << sec;
//		}
//		else
//		{
//			cout << sec;
//		}
//		cout << "] ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
//	}
//}
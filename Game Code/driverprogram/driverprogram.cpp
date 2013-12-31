// driverprogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IInterface.h"
#include <iostream>
#include <vector>
#include <DMLogger.h>
using namespace DMAstar;
using namespace DMLogger;
void TEST_DMAstarDLL();
void TEST_DMLibDLL();
void TEST_DMLoggerDLL();
void displaymap(int h,int w,std::vector<std::vector<char>>);

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleTitle(L"Driver Program");
	std::cout << "Testing DMAstarDLL.dll" << std::endl;
	TEST_DMAstarDLL();
	std::cout << "Testing DMLibDLL.dll" << std::endl;
	TEST_DMLibDLL();
	std::cout << "Testing DMLoggerDLL.dll" << std::endl;
	TEST_DMLoggerDLL();
	return 0;
}

//tests.
void TEST_DMAstarDLL()
{
	std::vector<std::vector<char>> myarray;
	IInterface myint = IInterface();
	const int WIDTH = 8;
	const int HEIGHT = 8;
	char map[HEIGHT][WIDTH] = 
	{{'0','0','0','0','0','0','0','0'},
	 {'0','1','1','1','1','1','1','0'},
	 {'0','1','0','0','0','0','0','0'},
	 {'0','1','0','1','1','1','1','1'},
	 {'0','1','0','1','0','0','0','1'},
	 {'0','1','0','0','0','1','0','0'},
	 {'0','1','1','1','1','1','1','0'},
	 {'0','0','0','0','0','0','0','0'}};
	for(int h = 0; h < HEIGHT;h++)
	{
		std::vector<char> temp;
		for(int w = 0; w< WIDTH;w++)
		{
			temp.push_back(map[h][w]);
		}
		myarray.push_back(temp);
	}
	std::cout << "Map before pathing:" << std::endl;
	displaymap(HEIGHT,WIDTH,myarray);
	myint.setMap(HEIGHT,WIDTH,myarray);
	myint.setEnd(7,7);
	myint.setStart(0,0);
	myint.computePath();
	std::vector<Point> temp = myint.getPath();

	std::cout << "Path: ";
	for (int i = 0; i < temp.size();i++)
	{
		if(i == 0)
		{
			myarray[temp[i].getY()][temp[i].getX()] = 'E';
		}
		else if(i == temp.size())
		{
			myarray[temp[i].getY()][temp[i].getX()] = 'S';
		}
		else
		{
			myarray[temp[i].getY()][temp[i].getX()] = 'X';
		}
		std::cout << temp[i];
	}
	std::cout << std::endl;
	std::cout << "Map after pathing:" << std::endl;
	displaymap(HEIGHT,WIDTH,myarray);
	std::cout << "Testing DMAstarDLL.dll - Done!" << std::endl;
	system("pause");//HACK: remove me before releace.
}
void TEST_DMLibDLL()
{
	system("pause");//HACK: remove me before releace.
}
void TEST_DMLoggerDLL()
{
	Log::Info() << "Im a test info";
	Log::Ok() << "Im a test OK";
	Log::Warn() << "Im a test warning";
	Log::Error() << "Im a test error";
	system("pause");//HACK: remove me before releace.
}

void displaymap(int h,int w,std::vector<std::vector<char>> map)
{
	for(int h1 = 0; h1 < h;h1++)
	{
		for(int w1 = 0; w1< w;w1++)
		{
			std::cout << map[h1][w1];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

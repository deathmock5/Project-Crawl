#pragma once
//=================================
// include guard
#ifndef _GameEntityPath_H_
#define _GameEntityPath_H_
//=================================
// forward declared dependencies
class Point;
//=================================
// included dependencies
#include <iostream>
#include <queue>
#include "Node.h"
#include "Point.h"
#include "SystemVars.h"

using namespace std;
//=================================
// the actual class
class GameEntityPath
{
public:
	GameEntityPath(void);
	void setMyLocation(Point location);
	void setTargetLocation(Point target);
	void setMap(int	map[19][25]);
	bool locationHasBeenSet();
	bool targetHasBeenSet();
	bool mapHasBeenSet();
	bool pathHasBeenComputed();
	void beginPathing();
	int moveThisDirectionOneSpaceToGetToGoal();
	~GameEntityPath(void);
private:
	string computePath();
	//members
	Point mylocation;
	Point mytarget;
	int map[19][25];
	bool hasvalidlocation;
	bool hasvalidtarget;
	bool hasvlidmap;
	string pathtoplayer;
	//pathfinding
	
	int n; // horizontal size of the map
	int m; // vertical size size of the map
	int dir; // number of possible directions to go at any position
};

#endif
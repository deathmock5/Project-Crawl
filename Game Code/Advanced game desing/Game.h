#pragma once
//=================================
// include guard
#ifndef _GAME_H_
#define _GAME_H_

//=================================
// forward declared dependencies
class GameObject;
class Player;
class Dungion;
//=================================
// included dependencies
#include "SystemVars.h"
#include "GameObject.h"
#include <iostream>
#include <vector>
using namespace std;
//=================================
// the actual class
class Game
{
public:
	Game(void);
	void registerGameObject(GameObject * s);
	void unregisterGameObject(GameObject * s);
	void sendMessageToAllObjects(string message);
	void sendMessageToAllObjects(string message,CLASSTYPE recip);
	~Game(void);
private:
	vector<GameObject*> gameobjects;
	int numberofobjects;
	int numberofcreatedobjects;
};
#endif

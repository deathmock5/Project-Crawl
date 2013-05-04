#pragma once
//=================================
// include guard
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

//=================================
// forward declared dependencies
enum CLASSTYPE;
//=================================
// included dependencies
#include <iostream>
#include "SystemVars.h"
using namespace std;

//=================================
// the actual class

class GameObject
{
public:
	GameObject();
	GameObject(CLASSTYPE);
	~GameObject(void);
	virtual void sendMessage(string data);
	CLASSTYPE getMyClassType();
	void setMyClassType(CLASSTYPE newrecip);
	void setId(int val);
	int getId();
private:
	//CLASSTYPE _MYCURRENTCLASSTYPE;
	int myid;
	CLASSTYPE MYTYPE;
};
#endif

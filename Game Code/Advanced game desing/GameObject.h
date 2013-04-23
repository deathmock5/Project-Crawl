#pragma once
//=================================
// include guard
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <iostream>
#include "SystemVars.h"
using namespace std;

//=================================
// the actual class
const enum CLASSTYPE{CLASSTYPE_NULL,CLASSTYPE_PLAYER,CLASSTYPE_DUNGION,CLASSTYPE_ENTITY,CLASSTYPE_MAP,CLASSTYPE_MENU};
class GameObject
{
public:
	GameObject();
	GameObject(CLASSTYPE mytype);
	~GameObject(void);

	virtual void sendMessage(string data,CLASSTYPE recip);
	virtual CLASSTYPE getMyClassType();
	virtual void setMyClassType(CLASSTYPE newrecip);
protected:
	const CLASSTYPE _MYCURRENTCLASSTYPE;
};
#endif

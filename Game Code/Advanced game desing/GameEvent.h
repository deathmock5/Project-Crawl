#pragma once
//guards
#ifndef _GAMEEVENT_H_
#define _GAMEEVENT_H_
//forwards

//dependencys
#include <string>
#include <vector>
#include "SystemVars.h"
using namespace std;

class GameEvent
{
public:
	GameEvent();
	~GameEvent(void);
	virtual void applyEvent();
	virtual void setEventPramiters(int,...);
	int getMyTimedActivator();
protected:
	GAMEEVENTTYPE mytype;
	int mytimedactivator;
	string myidentactivator;
	string posibleidentiget;
	string datamessage;
};
#endif

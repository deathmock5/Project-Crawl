#include "GameEventDialog.h"
#include "GameEvent.h"

GameEventDialog::GameEventDialog(void): GameEvent()
{

}

GameEventDialog::~GameEventDialog(void)
{
	//deconstructor
}

void GameEventDialog::applyEvent()
{
	//menu.addDialog(faceimg,text);
	//menu.showDialog();
	getGameRefrence()->sendMessageToAllObjects(datamessage,CLASSTYPE_MENU);
	getGameRefrence()->sendMessageToAllObjects(posibleidentiget,CLASSTYPE_EVENTMANAGER);
}

void GameEventDialog::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage = "DIALO_" + va_arg(messages,string) + ",";
	datamessage += va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);
}

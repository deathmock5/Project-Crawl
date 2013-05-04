#include "GameEventDialog.h"
#include "GameEvent.h"

GameEventDialog::GameEventDialog(void): GameEvent()
{

}

GameEventDialog::~GameEventDialog(void)
{
	//deconstructor
}

void GameEventDialog::applyEvent(Dungion& dung,Menu& menu)
{
	menu.addDialog(faceimg,text);
	menu.showDialog();
}

void GameEventDialog::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = va_arg(messages,int);
	myidentactivator = va_arg(messages,string);
	faceimg = load_image(myconcat(2,"\\Images\\Faces\\",va_arg(messages,string)));
	text = va_arg(messages,string);
	if(number == 5)
	{
		 posibleidentiget = va_arg(messages,string);
	}
	else
	{
		posibleidentiget = "null";
	}
}

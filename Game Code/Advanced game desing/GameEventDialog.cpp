#include "GameEventDialog.h"


GameEventDialog::GameEventDialog(void)
{
	int timedactivator = -1;
	string identactivator = "null";
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

	timedactivator = va_arg(messages,int);
	faceimg = load_image(myconcat(2,"\\Images\\Faces\\",va_arg(messages,string)));
	text = va_arg(messages,string);
	if(number > 3)
	{
		identactivator = va_arg(messages,string);
	}
}

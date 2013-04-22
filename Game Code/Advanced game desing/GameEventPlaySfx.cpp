#include "GameEventPlaySfx.h"


GameEventPlaySfx::GameEventPlaySfx(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventPlaySfx::~GameEventPlaySfx(void)
{

}
void GameEventPlaySfx::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: playsfx
}
void GameEventPlaySfx::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = va_arg(messages,int);
	sfx = load_sound(myconcat(2,"Sounds\\SFX\\",va_arg(messages,string)));
	if(number > 2)
	{
		myidentactivator = va_arg(messages,string);
	}
}
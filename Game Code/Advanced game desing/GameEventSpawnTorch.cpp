#include "GameEventSpawnTorch.h"


GameEventSpawnTorch::GameEventSpawnTorch(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventSpawnTorch::~GameEventSpawnTorch(void)
{
}

void GameEventSpawnTorch::applyEvent(Dungion& dung,Menu& menu)
{
	dung.reftoCurrentMap()->spawnEnttityInMap(torchent);
}
void GameEventSpawnTorch::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	timedactivator = va_arg(messages,int);
	torchent = Entity(myconcat(2,"Monster\\","torch.dngmn"));
	Bounds newbounds = torchent.getBounds();
	newbounds.setX(va_arg(messages,int));
	newbounds.setY(va_arg(messages,int));
	torchent.setBounds(newbounds);
	if(number > 3)
	{
		identactivator = va_arg(messages,string);
	}
}


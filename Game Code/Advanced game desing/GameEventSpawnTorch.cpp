#include "GameEventSpawnTorch.h"


GameEventSpawnTorch::GameEventSpawnTorch(void): GameEvent()
{

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

	mytimedactivator = va_arg(messages,int);
	torchent = Entity(myconcat(2,"Monster\\","torch.dngmn"));
	Bounds newbounds = torchent.getBounds();
	newbounds.setX(va_arg(messages,int));
	newbounds.setY(va_arg(messages,int));
	torchent.setBounds(newbounds);
	if(number > 3)
	{
		myidentactivator = va_arg(messages,string);
	}
}


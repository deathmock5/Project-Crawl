#include "Entity.h"
Entity::Entity(float spawnx,float spawny)
{
}
Entity::~Entity()
{
}
void Entity::draw(float originposx,float originposy){}
void Entity::travelToPos(float tarx,float tary,float speed){}
void Entity::update(std::vector<Player> players,int numplayers,Map curentmap){}
bool Entity::isLiveingCreature(){return true;}
bool Entity::isAlive(){return true;}
void Entity::drawLight(){}
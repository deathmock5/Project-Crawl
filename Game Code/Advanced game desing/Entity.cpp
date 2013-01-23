#include "Entity.h"
Entity::Entity(float spawnx,float spawny)
{
}
Entity::~Entity()
{
}
void Entity::draw(){}
void Entity::travelToPos(float tarx,float tary,float speed){}
void Entity::update(){}

bool Entity::isLiveingCreature(){return true;}
bool Entity::isAlive(){return true;}
void Entity::drawLight(){}
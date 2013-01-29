#include"Variables.h"
#include <iostream>
#include <string>
using namespace std;

class DealDamage
{
private:

	int totalDamageHero, totalDamageEnemy;
public:
	
	int getHeroAttackPower();
	int getHeroDefence();
	int getEnemyAttack();
	int getEnemyDefence();
	bool isRanged();
	bool isMagic();
	bool isMelee();
	void setHeroAttackPower();
	void setHeroDefence();
	void setEnemyAttack();
	void setEnemyDefence();
	void combat();
};

//get and set methods for variables

int DealDamage::getHeroAttackPower()
{
	return heroAttackPower;
}

int DealDamage::getHeroDefence()
{
	return heroDefence;
}

int DealDamage::getEnemyAttack()
{
	return monsterAttackPower;
}

int DealDamage::getEnemyDefence()
{
	return monsterDefence;
}
/*
for later use

bool DealDamage::isRanged()
{
	return ranged;
}

bool DealDamage::isMagic()
{
	return magic;
}

bool DealDamage::isMelee()
{
	return melee;
}
*/

void DealDamage::setHeroAttackPower()
{
	cout << "Set the Heros Attack power: ";
	cin >> heroAttackPower;
	if(heroAttackPower < 0)
		heroAttackPower = 0;
}

void DealDamage::setHeroDefence()
{
	cout << "Set the Heros Defence power: ";
	cin >> heroDefence;
	if(heroDefence < 0)
		heroDefence = 0;
}

void DealDamage::setEnemyAttack()
{
	cout << "Set the Monsters Attack power: ";
	cin >>monsterAttackPower;
	if(monsterAttackPower < 0)
		monsterAttackPower = 0;
}

void DealDamage::setEnemyDefence()
{
	cout << "Set the monsters defence power: ";
	cin >> monsterDefence;
	if(monsterDefence < 0)
		monsterDefence = 0;
}


//calculates and outputs damage taken by enemy and hero *Bonus damage not included yet*
void DealDamage::combat()
{
	setHeroAttackPower();
	setHeroDefence();
	setEnemyAttack();
	setEnemyDefence();

	//damage hero takes
	totalDamageHero = getEnemyAttack() - getHeroDefence();
	//damage enemy takes
	totalDamageEnemy = getHeroAttackPower() - getEnemyDefence();
	//output to screen
	cout << "The enemy has taken: " << totalDamageEnemy << " points of damage\n";
	cout << "The hero has taken: " << totalDamageHero << " points of damage\n";
}


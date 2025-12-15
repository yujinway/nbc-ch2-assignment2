#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

Monster::Monster(string name) : name(name),
HP(10), power(30), defence(10), speed(10)
{
}

void Monster::attack(Player* player)
{
	int rawDamage = power - player->getDefence();
	int damage = rawDamage > 0 ? rawDamage : 1;

	cout << name << "이 당신을 공격합니다!" << endl;
	player->setHP(player->getHP() - damage);
	cout << "* " << player->getNickname() << "에게 " << damage << "의 피해를 입혔다!" << endl;
	cout << "* " << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
}

string Monster::getName() const
{
	return name;
}

int Monster::getHP() const
{
	return HP;
}

int Monster::getPower() const
{
	return power;
}

int Monster::getDefence() const
{
	return defence;
}

int Monster::getSpeed() const
{
	return speed;
}

void Monster::setName(string name)
{
	this->name = name;
}

void Monster::setHP(int HP)
{
	this->HP = (HP > 0) ? HP : 0;
}

void Monster::setPower(int power)
{
	this->power = power;
}

void Monster::setDefence(int defence)
{
	this->defence = defence;
}

void Monster::setSpeed(int speed)
{
	this->speed = speed;
}

#include "Magician.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Magician::Magician(string nickname) : Player(nickname)
{
	job_name = "마법사";
	cout << "* 마법사로 전직했습니다." << endl;

	setMP(80);
}

void Magician::attack()
{
	cout << "공격: 마법을 시전한다!" << endl;
}

void Magician::attack(Monster* monster)
{
	int rawDamage = power - monster->getDefence();
	int damage = rawDamage > 0 ? rawDamage : 1;

	monster->setHP(monster->getHP() - damage);
	cout << "* " << monster->getName() << "에게 " << damage << "의 피해를 입혔다!" << endl;
	cout << "* " << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
}


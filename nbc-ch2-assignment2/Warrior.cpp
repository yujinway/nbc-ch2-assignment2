#include "Warrior.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string nickname) : Player(nickname)
{
	job_name = "전사";
	cout << "* 전사로 전직했습니다." << endl;

	setHP(80);
}

void Warrior::attack()
{
	cout << "공격: 검을 휘두른다!" << endl;
}

void Warrior::attack(Monster* monster)
{
	int rawDamage = power - monster->getDefence();
	int damage = rawDamage > 0 ? rawDamage : 1;

	monster->setHP(monster->getHP() - damage);
	cout << "* " << monster->getName() << "에게 " << damage << "의 피해를 입혔다!" << endl;
	cout << "* " << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
}

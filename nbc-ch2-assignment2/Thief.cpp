#include "Thief.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
	job_name = "도적";
	cout << "* 도적으로 전직했습니다." << endl;

	setSpeed(80);
}

void Thief::attack()
{
	cout << "공격: 단검을 휘두른다!" << endl;
}

void Thief::attack(Monster* monster)
{
	int rawDamage = (power - monster->getDefence()) / 5;
	int damage = rawDamage > 0 ? rawDamage : 1;

	for (int i = 0; i < 5; i++)
	{
		monster->setHP(monster->getHP() - damage);
		cout << "* " << monster->getName() << "에게 " << damage << "의 피해를 입혔다!" << endl;

		if (monster->getHP() <= 0)
		{
			break;
		}
	}
	cout << "* " << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
}


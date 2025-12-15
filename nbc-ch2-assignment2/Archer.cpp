#include "Archer.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Archer::Archer(string nickname) : Player(nickname)
{
	job_name = "궁수";
	cout << "* 궁수로 전직했습니다." << endl;

	setAccuracy(80);
}

void Archer::attack()
{
	cout << "공격: 화살을 발사한다!" << endl;
}

void Archer::attack(Monster* monster)
{
	int rawDamage = (power - monster->getDefence()) / 3;
	int damage = rawDamage > 0 ? rawDamage : 1;

	for (int i = 0; i < 3; i++)
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

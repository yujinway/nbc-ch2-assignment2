#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"

using namespace std;

int main() {
	string jobs[] = { "전사", "마법사", "도적", "궁수" };
	int job_choice = 0;
	string nickname;

	Player* player = nullptr;

	cout << "닉네임을 입력해주세요: ";
	cin >> nickname;

	cout << "<전직 시스템>" << endl;
	cout << nickname << "님, 환영합니다!" << endl;
	cout << "* 원하시는 직업을 선택해주세요." << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << (i + 1) << ". " << jobs[i] << endl;
	}

	cout << "선택: ";
	cin >> job_choice;

	switch (job_choice)
	{
	case 1:
		player = new Warrior(nickname);
		break;

	case 2:
		player = new Magician(nickname);
		break;

	case 3:
		player = new Thief(nickname);
		break;

	case 4:
		player = new Archer(nickname);
		break;

	default:
		cout << "잘못된 입력입니다." << endl;
		return 1;
	}

	//player->attack();
	player->printPlayerStatus();

	bool isBattleRunning = true;
	int attack_choice = 0;
	Monster* monster = new Monster("Goblin");

	cout << "야생의 " << monster->getName() << "이 나타났다!" << endl;

	while (isBattleRunning)
	{
		cout << "공격하시겠습니까?" << endl;
		cout << "1. 공격한다" << endl;
		cout << "2. 도망친다" << endl;
		cout << "선택: ";
		cin >> attack_choice;
		cout << "------------------------------------" << endl;

		switch (attack_choice)
		{
		case 1:
			//1. Player's turn
			player->attack(monster);

			if (monster->getHP() == 0)
			{
				cout << "전투에서 승리했습니다!" << endl;
				isBattleRunning = false;
				break;
			}
			cout << "------------------------------------" << endl;

			//2. Monster's turn
			monster->attack(player);
			cout << "------------------------------------" << endl;

			if (player->getHP() == 0)
			{
				cout << "당신은 패배했습니다..." << endl;
				isBattleRunning = false;
				break;
			}
			break;

		case 2:
			cout << monster->getName() << "에게서 도망쳤다!" << endl;
			isBattleRunning = false;
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}

	if (player != nullptr)
	{
		delete player;
	}

	if (monster != nullptr)
	{
		delete monster;
	}

	return 0;
}
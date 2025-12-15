#pragma once
#include <string>

class Monster;

class Player
{
public:
	Player(std::string nickname);
	virtual ~Player();

	virtual void attack() = 0;
	virtual void attack(Monster* monster) = 0;
	void printPlayerStatus() const;

	//getter
	std::string getJobName() const;
	std::string getNickname() const;
	int getLevel() const;
	int getHP() const;
	int getMP() const;
	int getPower() const;
	int getDefence() const;
	int getAccuracy() const;
	int getSpeed() const;

	//setter
	void setNickname(std::string nickname);
	void setHP(int HP);
	void setMP(int MP);
	void setPower(int power);
	void setDefence(int defence);
	void setAccuracy(int accuracy);
	void setSpeed(int speed);

protected:
	std::string job_name;
	std::string nickname;
	int level;
	int HP;
	int MP;
	int power;
	int defence;
	int accuracy;
	int speed;
};


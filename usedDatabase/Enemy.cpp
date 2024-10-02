#include "Enemy.h"


Enemy::Enemy()
{
	characterName = "빅우드";
	characterDesc = "마조히스트 나무 정령!";
	maxHp = 120;
	curHp = maxHp;
	Addshield = 10;
	curShield = 10;
	Damage = 30;
	criticalRate = 0.1f;
	Gold = 100;
}

void Enemy::attack() const
{
}

void Enemy::CharacterInfo() const
{
	MoveCursor::getInstance()->GotoXY(25, 4); std::cout << "사도의 이름: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 6); std::cout << "사도의 설명: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(25, 8); std::cout << "최대체력: " << maxHp << " / " << "현재체력: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 10); std::cout << "캐릭터 공격력: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 12); std::cout << "현재 쉴드량: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 14); std::cout << "현재 치명타확률: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 16); std::cout << "현재 보유 골드: " << Gold << "\n\n";
}

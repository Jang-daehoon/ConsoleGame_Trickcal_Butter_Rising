#include "Enemy.h"


Enemy::Enemy()
{
	characterName = "����";
	characterDesc = "��������Ʈ ���� ����!";
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
	MoveCursor::getInstance()->GotoXY(25, 4); std::cout << "�絵�� �̸�: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 6); std::cout << "�絵�� ����: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(25, 8); std::cout << "�ִ�ü��: " << maxHp << " / " << "����ü��: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 10); std::cout << "ĳ���� ���ݷ�: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 12); std::cout << "���� ���差: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 14); std::cout << "���� ġ��ŸȮ��: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 16); std::cout << "���� ���� ���: " << Gold << "\n\n";
}

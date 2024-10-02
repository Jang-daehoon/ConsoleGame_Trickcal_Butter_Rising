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

void Enemy::attack(Character& target) const
{
	// ���� �õ� ���� (�ѹ��� ȣ��)
	srand(static_cast<unsigned int>(time(0)));

	// �⺻ ���� ����: Damage�� 60% ������
	float physicalDamage = Damage * 0.6f;

	// ġ��Ÿ Ȯ�� ���
	int critChance = rand() % 100;
	if (critChance < (criticalRate * 100)) {
		// ġ��Ÿ �߻� �� 1.5�� ������
		float criticalDamage = Damage * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48);
		std::cout << "���尡 ġ��Ÿ ������ �Ͽ� " << criticalDamage << "�� ���ظ� �������ϴ�!" << std::endl;
		target.takeDamage(criticalDamage); // ��󿡰� �������� ��
	}
	else {
		// �Ϲ� ����
		MoveCursor::getInstance()->GotoXY(0, 48);
		std::cout << "���尡 �����Ͽ� " << physicalDamage << "�� ���ظ� �������ϴ�!" << std::endl;
		target.takeDamage(physicalDamage); // ��󿡰� �������� ��
	}
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

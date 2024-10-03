#include "Enemy.h"

Enemy::Enemy()
{
	characterName = "����";
	characterDesc = "��������Ʈ ��������!";
	maxHp = 200;
	curHp = maxHp;
	Damage = 50;
	criticalRate = 0.01;
	Gold = 200;
}

void Enemy::attack(Character& target) const
{
    // ���� �õ� ���� (�ѹ��� ȣ��)
    srand(static_cast<unsigned int>(time(0)));

    // �⺻ ���� ����
    float physicalDamage = Damage;

    // ġ��Ÿ Ȯ�� ���
    int critChance = rand() % 100;
    float finalDamage;

    // Ÿ���� ���常ŭ ���ظ� ����
    float shieldDamage = target.getCurShield(); // ���� ���� ��������
    if (shieldDamage > 0)
    {
        // ���尡 �ִ� ���, ���忡 ���� ���ظ� ����
        if (physicalDamage <= shieldDamage)
        {
            MoveCursor::getInstance()->GotoXY(0, 48);
            std::cout << "���尡 ���������� ����� ���� ���ذ� �����ϴ�!" << std::endl;
            target.BlockShield(shieldDamage - physicalDamage); // ���带 ���� ���ظ�ŭ ����
            return; // ���ذ� ������ ����
        }
        else
        {
            physicalDamage -= shieldDamage; // ���带 ������ �� ���� ���ظ� ���
            target.BreakShield(0); // ���带 0���� ����
            MoveCursor::getInstance()->GotoXY(0, 48);
            std::cout << "���尡 ���忡 �����Ͽ� " << shieldDamage << "�� ���ظ� �޾� ���带 ��� �����߽��ϴ�!" << std::endl;
        }
    }

    // ġ��Ÿ �߻� ���� Ȯ��
    if (critChance < (criticalRate * 100)) {
        // ġ��Ÿ �߻� �� 1.5�� ������
        finalDamage = physicalDamage * 1.5f;
        MoveCursor::getInstance()->GotoXY(0, 48);
        std::cout << "���尡 ġ��Ÿ ������ �Ͽ� " << finalDamage << "�� ���ظ� �������ϴ�!" << std::endl;
    }
    else {
        // �Ϲ� ����
        finalDamage = physicalDamage;
        MoveCursor::getInstance()->GotoXY(0, 48);
        std::cout << "���尡 �����Ͽ� " << finalDamage << "�� ���ظ� �������ϴ�!" << std::endl;
    }

    // Ÿ�ٿ��� ���� �������� ��
    target.takeDamage(finalDamage);
}


void Enemy::CharacterInfo() const
{
	MoveCursor::getInstance()->GotoXY(25, 4); std::cout << "�絵�� �̸�: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 6); std::cout << "�絵�� ����: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(25, 8); std::cout << "�ִ�ü��: " << maxHp << " / " << "����ü��: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 10); std::cout << "ĳ���� ���ݷ�: " << Damage;
    MoveCursor::getInstance()->GotoXY(25, 12); std::cout << "���� ġ��ŸȮ��: " << criticalRate * 100 << "%";
    MoveCursor::getInstance()->GotoXY(25, 14); std::cout << "���� ���� ���: " << Gold;
}

void Enemy::EnemyUpgrade()
{
	characterName = "����";
	characterDesc = "��������Ʈ ��������!";
	maxHp += 150;
	curHp = maxHp;
	Damage += 15;
	criticalRate += 0.05;
	Gold += 200;
}

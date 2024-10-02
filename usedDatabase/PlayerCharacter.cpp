#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	characterName = "����";
	characterDesc = "ģ�� ���� ����";
	maxHp = 100;
	curHp = maxHp;
	Addshield = 5;
	curShield = 5;
	Damage = 30;
	criticalRate = 0.1f;
	Gold = 100;

	maxYellowcard = 100;
	yellowCard = 0;
	maxMana = 100;
	mana = 0;

	maxCost = 10;
	curCost = maxCost;
	maxBattlecost = 5;
	curBattlecost = maxBattlecost;
	maxExp = 20;
	curexp = 0;

	grade = 1;
	maxGrade = 6;

}

//getter, setter 
int PlayerCharacter::GetYellowCard()
{
	return yellowCard;
}
void PlayerCharacter::SetYellowCard()
{
}
int PlayerCharacter::GetMaxYellowCard()
{
	return maxYellowcard;
}
int PlayerCharacter::GetMana()
{
	return mana;
}
void PlayerCharacter::SetMana()
{
	mana += 10;
	if (mana >= maxMana)
	{
		mana = maxMana;
	}
}
int PlayerCharacter::GetMaxMana()
{
	return maxMana;
}
void PlayerCharacter::SetMaxMana()
{
}

void PlayerCharacter::UsedMana()
{
	mana = 0;
}

int PlayerCharacter::GetCurCost()
{
	return curCost;
}

void PlayerCharacter::usedCurCost()
{
	curCost--;
	if (curCost < 0)
	{
		curCost = 0;
	}
}

void PlayerCharacter::initCurCost()
{
	curCost = maxCost;
}

int PlayerCharacter::GetBattleCost()
{
	return maxBattlecost;
}

void PlayerCharacter::UsedBattleCost()
{
	curBattlecost--;
}

void PlayerCharacter::UsedSkillCost()
{
	curBattlecost = 0;
}

int PlayerCharacter::getCurBattleCost()
{
	return curBattlecost;
}



void PlayerCharacter::InitCurBattleCost()
{
	curBattlecost = maxBattlecost;
}

int PlayerCharacter::GetMaxCost()
{
	return maxCost;
}

void PlayerCharacter::SetMaxCost()
{
}

void PlayerCharacter::SetExp(int addExp)
{
	curexp += addExp;
	//�ִ� ����ġ �ʰ� �� �ʰ� ����ġ��ŭ �߰� ȹ��
	if (curexp >= maxExp)
	{
		int ExcessExp = 0;
		ExcessExp = maxExp - curexp;
		curexp = 0;
		curexp += ExcessExp;
		//LevelUp�޼��� ȣ��
		LevelUp();
	}
}

void PlayerCharacter::LevelUp()
{
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "�г�����!!";
	Sleep(1000);	//1�� ���
	if (grade != maxGrade)
	{
		//�г�����
		grade++;
		//�г⸶�� �߰� ������ �ٸ����� �ۼ�
		if (grade == 2)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "�г��� �Ǿ����!";
			//�� ���� ����
			IncreAllStat(10, 10, 0.01, 5, maxExp);
		}
		else if (grade == 3)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "�г��� �Ǿ����!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == 4)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "�г��� �Ǿ����!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == 5)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "�г��� �Ǿ����!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == maxGrade)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "�г��� �Ǿ����!";
			IncreAllStat(50, 50, 0.05, 10, 9999);
		}

	}
}

void PlayerCharacter::IncreAllStat(int IncreMaxhp, int IncreDmg, int IncreCriRate, int IncreMaxCost, int IncreMaxExp)
{
	maxHp += IncreMaxhp;
	Damage += IncreDmg;
	criticalRate +=IncreCriRate;
	maxCost += IncreMaxCost;
	maxExp += IncreMaxExp;
}

/// <summary> ����
///¯���� �߻��� ������ ���� ���ظ� ������.
/// ���� ���� : Damage�� 55% ������ 
///���� Ȯ���� ������ �߻��� ������ Ȯ�� ġ��Ÿ ���� ���ظ� ������.
///��ȭ�� ���� ���� : Damage�� 70 % ������ 
///ġ��Ÿ�� ������ 1.5�� �������� �ش�.
/// </summary>
void PlayerCharacter::attack(Character& target) const
{
	// ���� �õ� ���� (�ѹ��� ȣ��)
	srand(static_cast<unsigned int>(time(0)));

	// �⺻ ���� ����: Damage�� 55% ������
	float physicalDamage = getDamage() * 0.55f;

	// ġ��Ÿ �Ǵ� ��ȭ�� ���� ���ظ� ���� Ȯ�� (0~99�� ���� ����)
	int critChance = rand() % 100;
	int enhancedAttackChance = rand() % 100; // ��ȭ ���� �߻� ���� üũ

	if (enhancedAttackChance < 10) { // 10% Ȯ���� ��ȭ ���� �߻�
		// ��ȭ ����: ������ ġ��Ÿ�� ó��
		float enhancedDamage = getDamage() * 0.70f * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "������ �߻��Ͽ� ������ " << enhancedDamage << " ��ŭ�� ġ��Ÿ ���ظ� �������ϴ�!" << std::endl;
		target.takeDamage(enhancedDamage); 
	}
	else if (critChance < (getCriticalRate() * 100)) {
		// ġ��Ÿ: Damage�� 70% ������ + 1.5�� �߰� ġ��Ÿ ����
		float criticalDamage = getDamage() * 0.55f * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "ũ��Ƽ�� ��Ʈ�� �����Ͽ� ������ " << criticalDamage << " ��ŭ�� ġ��Ÿ ���ظ� �������ϴ�!" << std::endl;
		target.takeDamage(criticalDamage); 
	}
	else {
		// �Ϲ� ����: ���� ����
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "¯���� �߻��Ͽ� ������ " << physicalDamage << " ��ŭ�� ���� ���ظ� �������ϴ�!" << std::endl;
		target.takeDamage(physicalDamage);
	};
}

//ĳ���� ���� ���
void PlayerCharacter::CharacterInfo() const
{
	MoveCursor::getInstance()->GotoXY(60, 10); std::cout << "�ִ� Cost: " << maxCost << " / " << "���� Cost: " << curCost;
	MoveCursor::getInstance()->GotoXY(50, 12); std::cout << "�絵�� �г�: " << grade;
	MoveCursor::getInstance()->GotoXY(50, 13); std::cout << "�絵�� �̸�: " << characterName;
	MoveCursor::getInstance()->GotoXY(50, 15); std::cout << "�絵�� ����: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(50, 17); std::cout << "�ִ�ü��: " << maxHp << " / " << "����ü��: " << curHp;
	MoveCursor::getInstance()->GotoXY(50, 19); std::cout << "�ִ븶��: " << maxMana << " / " << "���� ����: " << mana;
	MoveCursor::getInstance()->GotoXY(50, 21); std::cout << "�ִ� ����ī�� ����: " << maxYellowcard << " / " << "���� ����ī�� ����: " << yellowCard << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 23); std::cout << "ĳ���� ���ݷ�: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 25); std::cout << "���� ���差: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 27); std::cout << "���� ġ��ŸȮ��: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 29); std::cout << "���� ���� ���: " << Gold << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 31); std::cout << "�ִ� ����ġ: " << maxExp << " / " << "���� ����ġ: " << curexp << "\n\n";
}

void PlayerCharacter::CharacterBattleInfo()
{
	MoveCursor::getInstance()->GotoXY(15, 19); std::cout << "�����������������������������������";
	MoveCursor::getInstance()->GotoXY(25, 21); std::cout << "�ִ� BattleCost: " << maxBattlecost << " / " << "���� BattleCost: " << curBattlecost;
	MoveCursor::getInstance()->GotoXY(25, 23); std::cout << "�絵�� �г�: " << grade;
	MoveCursor::getInstance()->GotoXY(25, 25); std::cout << "�絵�� �̸�: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 27); std::cout << "�ִ�ü��: " << maxHp << " / " << "����ü��: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 29); std::cout << "�ִ븶��: " << maxMana << " / " << "���� ����: " << mana;
	MoveCursor::getInstance()->GotoXY(25, 31); std::cout << "�ִ� ����ī�� ����: " << maxYellowcard << " / " << "���� ����ī�� ����: " << yellowCard << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 33); std::cout << "ĳ���� ���ݷ�: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 35); std::cout << "���� ���差: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 37); std::cout << "���� ġ��ŸȮ��: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 39); std::cout << "���� ���� ���: " << Gold << "\n\n";
}

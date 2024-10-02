#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	characterName = "버터";
	characterDesc = "친구 좋아 좋아";
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
	//최대 경험치 초과 시 초과 경험치만큼 추가 획득
	if (curexp >= maxExp)
	{
		int ExcessExp = 0;
		ExcessExp = maxExp - curexp;
		curexp = 0;
		curexp += ExcessExp;
		//LevelUp메서드 호출
		LevelUp();
	}
}

void PlayerCharacter::LevelUp()
{
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "학년증가!!";
	Sleep(1000);	//1초 대기
	if (grade != maxGrade)
	{
		//학년증가
		grade++;
		//학년마다 추가 스텟이 다르도록 작성
		if (grade == 2)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "학년이 되었어요!";
			//올 스텟 증가
			IncreAllStat(10, 10, 0.01, 5, maxExp);
		}
		else if (grade == 3)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "학년이 되었어요!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == 4)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "학년이 되었어요!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == 5)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "학년이 되었어요!";
			IncreAllStat(50, 50, 0.05, 5, maxExp);
		}
		else if (grade == maxGrade)
		{
			MoveCursor::getInstance()->GotoXY(50, 36); std::cout << grade << "학년이 되었어요!";
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

/// <summary> 공격
///짱돌을 발사해 적에게 물리 피해를 입힌다.
/// 물리 피해 : Damage의 55% 데미지 
///일정 확률로 개껌을 발사해 적에게 확정 치명타 물리 피해를 입힌다.
///강화된 물리 피해 : Damage의 70 % 데미지 
///치명타가 터지면 1.5배 데미지를 준다.
/// </summary>
void PlayerCharacter::attack(Character& target) const
{
	// 랜덤 시드 설정 (한번만 호출)
	srand(static_cast<unsigned int>(time(0)));

	// 기본 물리 피해: Damage의 55% 데미지
	float physicalDamage = getDamage() * 0.55f;

	// 치명타 또는 강화된 물리 피해를 위한 확률 (0~99의 값을 얻음)
	int critChance = rand() % 100;
	int enhancedAttackChance = rand() % 100; // 강화 공격 발생 여부 체크

	if (enhancedAttackChance < 10) { // 10% 확률로 강화 공격 발생
		// 강화 공격: 무조건 치명타로 처리
		float enhancedDamage = getDamage() * 0.70f * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "개껌을 발사하여 적에게 " << enhancedDamage << " 만큼의 치명타 피해를 입혔습니다!" << std::endl;
		target.takeDamage(enhancedDamage); 
	}
	else if (critChance < (getCriticalRate() * 100)) {
		// 치명타: Damage의 70% 데미지 + 1.5배 추가 치명타 피해
		float criticalDamage = getDamage() * 0.55f * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "크리티컬 히트를 발휘하여 적에게 " << criticalDamage << " 만큼의 치명타 피해를 입혔습니다!" << std::endl;
		target.takeDamage(criticalDamage); 
	}
	else {
		// 일반 공격: 물리 피해
		MoveCursor::getInstance()->GotoXY(0, 48); std::cout << "짱돌을 발사하여 적에게 " << physicalDamage << " 만큼의 물리 피해를 입혔습니다!" << std::endl;
		target.takeDamage(physicalDamage);
	};
}

//캐릭터 정보 출력
void PlayerCharacter::CharacterInfo() const
{
	MoveCursor::getInstance()->GotoXY(60, 10); std::cout << "최대 Cost: " << maxCost << " / " << "남은 Cost: " << curCost;
	MoveCursor::getInstance()->GotoXY(50, 12); std::cout << "사도의 학년: " << grade;
	MoveCursor::getInstance()->GotoXY(50, 13); std::cout << "사도의 이름: " << characterName;
	MoveCursor::getInstance()->GotoXY(50, 15); std::cout << "사도의 설명: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(50, 17); std::cout << "최대체력: " << maxHp << " / " << "현재체력: " << curHp;
	MoveCursor::getInstance()->GotoXY(50, 19); std::cout << "최대마나: " << maxMana << " / " << "현재 마나: " << mana;
	MoveCursor::getInstance()->GotoXY(50, 21); std::cout << "최대 옐로카드 개수: " << maxYellowcard << " / " << "현재 옐로카드 개수: " << yellowCard << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 23); std::cout << "캐릭터 공격력: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 25); std::cout << "현재 쉴드량: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 27); std::cout << "현재 치명타확률: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 29); std::cout << "현재 보유 골드: " << Gold << "\n\n";
	MoveCursor::getInstance()->GotoXY(50, 31); std::cout << "최대 경험치: " << maxExp << " / " << "현재 경험치: " << curexp << "\n\n";
}

void PlayerCharacter::CharacterBattleInfo()
{
	MoveCursor::getInstance()->GotoXY(15, 19); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	MoveCursor::getInstance()->GotoXY(25, 21); std::cout << "최대 BattleCost: " << maxBattlecost << " / " << "남은 BattleCost: " << curBattlecost;
	MoveCursor::getInstance()->GotoXY(25, 23); std::cout << "사도의 학년: " << grade;
	MoveCursor::getInstance()->GotoXY(25, 25); std::cout << "사도의 이름: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 27); std::cout << "최대체력: " << maxHp << " / " << "현재체력: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 29); std::cout << "최대마나: " << maxMana << " / " << "현재 마나: " << mana;
	MoveCursor::getInstance()->GotoXY(25, 31); std::cout << "최대 옐로카드 개수: " << maxYellowcard << " / " << "현재 옐로카드 개수: " << yellowCard << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 33); std::cout << "캐릭터 공격력: " << Damage << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 35); std::cout << "현재 쉴드량: " << curShield << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 37); std::cout << "현재 치명타확률: " << criticalRate * 100 << "%" << "\n\n";
	MoveCursor::getInstance()->GotoXY(25, 39); std::cout << "현재 보유 골드: " << Gold << "\n\n";
}

#include "Character.h"
#include<iostream>
#pragma once
class PlayerCharacter : public Character
{
private:
	//옐로카드는 피격 시 증가 (받은 데미지 / 5 만큼 추가)
	int maxYellowcard;
	int yellowCard;

	//마나는 공격 시 회복 (Mana += 10) Mana == maxMana ->스킬 사용 가능
	int mana;
	int maxMana;

	int maxCost;
	int curCost;
	int maxBattlecost;
	int curBattlecost;
	float maxExp;
	float curexp;

	//학년
	int grade;
	int maxGrade;



public:
	PlayerCharacter();	//생성자

	int GetYellowCard();
	void SetYellowCard();
	int GetMaxYellowCard();

	//마나
	int GetMana();
	void SetMana();
	int GetMaxMana();
	void SetMaxMana();


	//전투MaxCost
	int GetBattleCost();
	void UsedBattleCost();
	//실 사용되는 전투 Cost
	int getCurBattleCost();
	void InitCurBattleCost();

	// MaxCost
	int GetMaxCost();
	void SetMaxCost();

	//성장에 실제로 사용되는 Cost
	int GetCurCost();
	void usedCurCost();
	void initCurCost();

	//경험치 증가, 레벨업, 올스텟 증가
	void SetExp(int addExp);
	void LevelUp();
	void IncreAllStat(int IncreMaxhp, int IncreDmg, int IncreCriRate, int IncreMaxCost, int IncreMaxExp  );	//올스텟 증가, 현재체력 최대체력으로 초기화
	
	//공격, 피격, 캐릭터 정보, 전투시 캐릭터 정보
	void attack()const override;
	void takeDamage(int Damage) override;
	void CharacterInfo() const override;
	void CharacterBattleInfo();


};


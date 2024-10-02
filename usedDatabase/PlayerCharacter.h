#include "Character.h"
#include<iostream>
#pragma once
class PlayerCharacter : public Character
{
private:
	//����ī��� �ǰ� �� ���� (���� ������ / 5 ��ŭ �߰�)
	int maxYellowcard;
	int yellowCard;

	//������ ���� �� ȸ�� (Mana += 10) Mana == maxMana ->��ų ��� ����
	int mana;
	int maxMana;

	int maxCost;
	int curCost;
	int maxBattlecost;
	int curBattlecost;
	float maxExp;
	float curexp;

	//�г�
	int grade;
	int maxGrade;



public:
	PlayerCharacter();	//������

	int GetYellowCard();
	void SetYellowCard();
	int GetMaxYellowCard();

	//����
	int GetMana();
	void SetMana();
	int GetMaxMana();
	void SetMaxMana();


	//����MaxCost
	int GetBattleCost();
	void UsedBattleCost();
	//�� ���Ǵ� ���� Cost
	int getCurBattleCost();
	void InitCurBattleCost();

	// MaxCost
	int GetMaxCost();
	void SetMaxCost();

	//���忡 ������ ���Ǵ� Cost
	int GetCurCost();
	void usedCurCost();
	void initCurCost();

	//����ġ ����, ������, �ý��� ����
	void SetExp(int addExp);
	void LevelUp();
	void IncreAllStat(int IncreMaxhp, int IncreDmg, int IncreCriRate, int IncreMaxCost, int IncreMaxExp  );	//�ý��� ����, ����ü�� �ִ�ü������ �ʱ�ȭ
	
	//����, �ǰ�, ĳ���� ����, ������ ĳ���� ����
	void attack()const override;
	void takeDamage(int Damage) override;
	void CharacterInfo() const override;
	void CharacterBattleInfo();


};


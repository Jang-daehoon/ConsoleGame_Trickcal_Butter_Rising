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

void Enemy::attack(Character& target) const
{
	// 랜덤 시드 설정 (한번만 호출)
	srand(static_cast<unsigned int>(time(0)));

	// 기본 물리 피해: Damage의 60% 데미지
	float physicalDamage = Damage * 0.6f;

	// 치명타 확률 계산
	int critChance = rand() % 100;
	if (critChance < (criticalRate * 100)) {
		// 치명타 발생 시 1.5배 데미지
		float criticalDamage = Damage * 1.5f;
		MoveCursor::getInstance()->GotoXY(0, 48);
		std::cout << "빅우드가 치명타 공격을 하여 " << criticalDamage << "의 피해를 입혔습니다!" << std::endl;
		target.takeDamage(criticalDamage); // 대상에게 데미지를 줌
	}
	else {
		// 일반 공격
		MoveCursor::getInstance()->GotoXY(0, 48);
		std::cout << "빅우드가 공격하여 " << physicalDamage << "의 피해를 입혔습니다!" << std::endl;
		target.takeDamage(physicalDamage); // 대상에게 데미지를 줌
	}
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

#include "Enemy.h"

Enemy::Enemy()
{
	characterName = "빅우드";
	characterDesc = "마조히스트 나무정령!";
	maxHp = 200;
	curHp = maxHp;
	Damage = 50;
	criticalRate = 0.01;
	Gold = 200;
}

void Enemy::attack(Character& target) const
{
    // 랜덤 시드 설정 (한번만 호출)
    srand(static_cast<unsigned int>(time(0)));

    // 기본 물리 피해
    float physicalDamage = Damage;

    // 치명타 확률 계산
    int critChance = rand() % 100;
    float finalDamage;

    // 타겟의 쉴드만큼 피해를 감소
    float shieldDamage = target.getCurShield(); // 현재 쉴드 가져오기
    if (shieldDamage > 0)
    {
        // 쉴드가 있는 경우, 쉴드에 먼저 피해를 입힘
        if (physicalDamage <= shieldDamage)
        {
            MoveCursor::getInstance()->GotoXY(0, 48);
            std::cout << "빅우드가 공격했지만 쉴드로 인해 피해가 없습니다!" << std::endl;
            target.BlockShield(shieldDamage - physicalDamage); // 쉴드를 물리 피해만큼 줄임
            return; // 피해가 없으면 종료
        }
        else
        {
            physicalDamage -= shieldDamage; // 쉴드를 제거한 후 남은 피해를 계산
            target.BreakShield(0); // 쉴드를 0으로 설정
            MoveCursor::getInstance()->GotoXY(0, 48);
            std::cout << "빅우드가 쉴드에 공격하여 " << shieldDamage << "의 피해를 받아 쉴드를 모두 소진했습니다!" << std::endl;
        }
    }

    // 치명타 발생 여부 확인
    if (critChance < (criticalRate * 100)) {
        // 치명타 발생 시 1.5배 데미지
        finalDamage = physicalDamage * 1.5f;
        MoveCursor::getInstance()->GotoXY(0, 48);
        std::cout << "빅우드가 치명타 공격을 하여 " << finalDamage << "의 피해를 입혔습니다!" << std::endl;
    }
    else {
        // 일반 공격
        finalDamage = physicalDamage;
        MoveCursor::getInstance()->GotoXY(0, 48);
        std::cout << "빅우드가 공격하여 " << finalDamage << "의 피해를 입혔습니다!" << std::endl;
    }

    // 타겟에게 최종 데미지를 줌
    target.takeDamage(finalDamage);
}


void Enemy::CharacterInfo() const
{
	MoveCursor::getInstance()->GotoXY(25, 4); std::cout << "사도의 이름: " << characterName;
	MoveCursor::getInstance()->GotoXY(25, 6); std::cout << "사도의 설명: " << characterDesc;
	MoveCursor::getInstance()->GotoXY(25, 8); std::cout << "최대체력: " << maxHp << " / " << "현재체력: " << curHp;
	MoveCursor::getInstance()->GotoXY(25, 10); std::cout << "캐릭터 공격력: " << Damage;
    MoveCursor::getInstance()->GotoXY(25, 12); std::cout << "현재 치명타확률: " << criticalRate * 100 << "%";
    MoveCursor::getInstance()->GotoXY(25, 14); std::cout << "현재 보유 골드: " << Gold;
}

void Enemy::EnemyUpgrade()
{
	characterName = "빅우드";
	characterDesc = "마조히스트 나무정령!";
	maxHp += 150;
	curHp = maxHp;
	Damage += 15;
	criticalRate += 0.05;
	Gold += 200;
}

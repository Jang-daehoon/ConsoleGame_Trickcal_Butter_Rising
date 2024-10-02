#include <string>
#include <ctime>   // 시간 시드를 설정하기 위한 라이브러리
#include<iostream>
#include "MoveCursor.h"

class Character {
protected:

    std::string characterName;  // 캐릭터 이름
    std::string characterDesc;  // 캐릭터 설명
    int maxHp;
    int curHp;
    int Addshield;  // 획득 쉴드량
    int curShield;  // 현재 보유중인 쉴드량	
    int Damage;     // 데미지
    float criticalRate;  // 크리티컬 확률
    int Gold;  // 초기 보유 골드

public:
    Character();  // 생성자
    Character(std::string charName, std::string charDesc, int MaxHp, int CurHp,
        int AddShield, int CurShield, int NEWDamage, float CriticalRate, int GETGold);

    // Getter 메서드
    std::string getCharacterName() const;
    std::string getCharacterDesc() const;
    int getMaxHp() const;
    int getCurHp() const;
    int getAddShield() const;
    int getCurShield() const;
    int getDamage() const;
    float getCriticalRate() const;
    int getGold() const;

    // Setter 메서드
    void setCharacterName(const std::string& name);
    void setCharacterDesc(const std::string& desc);
    void setMaxHp(int addMaxHp);
    void setCurHp(int hp);
    void setAddShield(int addShield);
    void setCurShield(int shield);
    void setDamage(int damage);
    void setCriticalRate(float rate);
    void setGold(int gold);

    // 가상 함수를 통해 자식 클래스에서 특정 동작을 오버라이딩
    virtual void attack() const = 0;  // 순수가상함수
    virtual void takeDamage(int Damage);
    virtual void CharacterInfo() const = 0;
};


#include "Character.h"

Character::Character()
{
    maxHp = 0;
    curHp = 0;
    Addshield = 0;
    curShield = 0;
    Damage = 0;
    criticalRate = 0.0f;
    Gold = 0;
}

Character::Character(std::string charName, std::string charDesc, int MaxHp, int CurHp, int AddShield, int CurShield, int NEWDamage, float CriticalRate, int GETGold)
{
    characterName = charName;
    characterDesc = charDesc;
    maxHp = MaxHp;
    curHp = CurHp;
    Addshield = AddShield;
    curShield = CurShield;
    Damage = NEWDamage;
    criticalRate = CriticalRate;
    Gold = GETGold;
}



// Getter 메서드 구현
std::string Character::getCharacterName() const {
    return characterName;
}

std::string Character::getCharacterDesc() const {
    return characterDesc;
}

int Character::getMaxHp() const {
    return maxHp;
}

int Character::getCurHp() const {
    return curHp;
}

int Character::getAddShield() const {
    return Addshield;
}

int Character::getCurShield() const {
    return curShield;
}

int Character::getDamage() const {
    return Damage;
}

float Character::getCriticalRate() const {
    return criticalRate;
}

int Character::getGold() const {
    return Gold;
}

// Setter 메서드 구현
void Character::setCharacterName(const std::string& name) {
    characterName = name;
}

void Character::setCharacterDesc(const std::string& desc) {
    characterDesc = desc;
}

void Character::setMaxHp(int addMaxHp) {
    maxHp += addMaxHp;
}

void Character::setCurHp(int hp) {
    curHp += hp;

    if (curHp > maxHp)  // HP는 maxHp가 넘지 않도록 체크
        curHp = maxHp;
}

void Character::setAddShield(int addShield) {
    Addshield += addShield;
}

void Character::setCurShield(int shield) {
    if (shield < 0) shield = 0;  // 쉴드도 음수가 되지 않도록 체크
    curShield += shield;
}

void Character::setDamage(int damage) {
    Damage += damage;
}

void Character::setCriticalRate(float rate) {
    if (rate < 0.0f) rate = 0.0f; // 크리티컬 확률도 음수가 되지 않도록 체크
    criticalRate += rate;
}

void Character::setGold(int gold) {
    if (gold < 0) gold = 0; // 골드도 음수가 되지 않도록 체크
    Gold += gold;
}

void Character::takeDamage(int Damage)
{
    curHp -= Damage;
    if (curHp < 0) {
        curHp = 0; // 체력이 0 이하가 되지 않도록 설정
    }
}


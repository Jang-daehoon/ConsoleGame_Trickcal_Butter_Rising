#include <string>
#include <ctime>   // �ð� �õ带 �����ϱ� ���� ���̺귯��
#include<iostream>
#include "MoveCursor.h"

class Character {
protected:

    std::string characterName;  // ĳ���� �̸�
    std::string characterDesc;  // ĳ���� ����
    int maxHp;
    int curHp;
    int Addshield;  // ȹ�� ���差
    int curShield;  // ���� �������� ���差	
    int Damage;     // ������
    float criticalRate;  // ũ��Ƽ�� Ȯ��
    int Gold;  // �ʱ� ���� ���

public:
    Character();  // ������
    Character(std::string charName, std::string charDesc, int MaxHp, int CurHp,
        int AddShield, int CurShield, int NEWDamage, float CriticalRate, int GETGold);

    // Getter �޼���
    std::string getCharacterName() const;
    std::string getCharacterDesc() const;
    int getMaxHp() const;
    int getCurHp() const;
    int getAddShield() const;
    int getCurShield() const;
    int getDamage() const;
    float getCriticalRate() const;
    int getGold() const;

    // Setter �޼���
    void setCharacterName(const std::string& name);
    void setCharacterDesc(const std::string& desc);
    void setMaxHp(int addMaxHp);
    void setCurHp(int hp);
    void setAddShield(int addShield);
    void setCurShield(int shield);
    void setDamage(int damage);
    void setCriticalRate(float rate);
    void setGold(int gold);

    // ���� �Լ��� ���� �ڽ� Ŭ�������� Ư�� ������ �������̵�
    virtual void attack() const = 0;  // ���������Լ�
    virtual void takeDamage(int Damage);
    virtual void CharacterInfo() const = 0;
};


#include "playerCharacter.h"

#pragma once
class Enemy : public Character
{
public:
	Enemy();

	// Character��(��) ���� ��ӵ�
	void attack() const override;
	void CharacterInfo() const override;
};


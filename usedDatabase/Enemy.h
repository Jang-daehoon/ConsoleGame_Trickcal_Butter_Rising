#include "playerCharacter.h"

#pragma once
class Enemy : public Character
{
public:
	Enemy();

	// Character을(를) 통해 상속됨
	void attack(Character& target) const override;
	void CharacterInfo() const override;
};


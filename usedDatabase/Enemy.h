#include "playerCharacter.h"

#pragma once
class Enemy : public Character
{
public:
	Enemy();
	void attack(Character& target) const override;
	void CharacterInfo() const override;
	void EnemyUpgrade();
};


#include<vector>
#include<random>

class GameManager; // 전방 선언

#pragma once
class Event
{
public:
	void eventSet();

	void IncreMaxHp1();
	void PlayWithNaia();
	void HardWorkerKomi();
	void DestroyTrash();
	void PickUpTheGun();
	void GetExp();
};


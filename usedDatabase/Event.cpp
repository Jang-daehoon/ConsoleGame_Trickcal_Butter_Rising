#include "Event.h"
#include<iostream>
#include "GameManager.h" // GameManager의 정의를 포함


void Event::eventSet()
{
	srand(static_cast<unsigned int>(time(0)));

	int RandomValue = rand() % 6 + 1; // 1~5 중 하나의 값

	switch (RandomValue)
	{
	case 1:
		IncreMaxHp1();
		break;
	case 2:
		PlayWithNaia();
		break;
	case 3:
		HardWorkerKomi();
		break;
	case 4:
		DestroyTrash();
		break;
	case 5:
		PickUpTheGun();
		break;
	case 6:
		GetExp();
		break;

	}
}

void Event::IncreMaxHp1()
{
	GameManager::getInstance()->myplayer.setMaxHp(20);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "쬰장님과 코미와 즐겁게 대화를 했다.";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout<< "(최대체력 20 증가)";
}

void Event::PlayWithNaia()
{
	GameManager::getInstance()->myplayer.setCriticalRate(0.05);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "나이아랑 물총과 새총을 쏘며";
		MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "더 아프게 맞추는 법을 배웠다!!!";
	MoveCursor::getInstance()->GotoXY(50, 37); std::cout << "(크리티컬 확률 5 % 증가)";
}

void Event::HardWorkerKomi()
{
	GameManager::getInstance()->myplayer.setCurHp(30);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "일을 하는 것 같지만 팔이 짧아";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "혼자 꿀을 빨고 있는 모습이다";
	MoveCursor::getInstance()->GotoXY(50, 37); std::cout << "(현재 체력 30 회복)";
}

void Event::DestroyTrash()
{
	GameManager::getInstance()->myplayer.setGold(100);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "쓰레기는 제거해야해...";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(골드 +100)";
}

void Event::PickUpTheGun()
{
	GameManager::getInstance()->myplayer.setDamage(10);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "어서 나를 주워!! 내 모든 힘을 너에게 주마!!";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(공격력 + 10)";
}

void Event::GetExp()
{
	GameManager::getInstance()->myplayer.SetExp(5);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "버터는 공부를 통해 경험치를 획득했습니다!!";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(경험치 + 5)";
}


#include "Event.h"
#include<iostream>
#include "GameManager.h" // GameManager�� ���Ǹ� ����


void Event::eventSet()
{
	srand(static_cast<unsigned int>(time(0)));

	int RandomValue = rand() % 6 + 1; // 1~5 �� �ϳ��� ��

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
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "�g��԰� �ڹ̿� ��̰� ��ȭ�� �ߴ�.";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout<< "(�ִ�ü�� 20 ����)";
}

void Event::PlayWithNaia()
{
	GameManager::getInstance()->myplayer.setCriticalRate(0.05);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "���̾ƶ� ���Ѱ� ������ ���";
		MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "�� ������ ���ߴ� ���� �����!!!";
	MoveCursor::getInstance()->GotoXY(50, 37); std::cout << "(ũ��Ƽ�� Ȯ�� 5 % ����)";
}

void Event::HardWorkerKomi()
{
	GameManager::getInstance()->myplayer.setCurHp(30);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "���� �ϴ� �� ������ ���� ª��";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "ȥ�� ���� ���� �ִ� ����̴�";
	MoveCursor::getInstance()->GotoXY(50, 37); std::cout << "(���� ü�� 30 ȸ��)";
}

void Event::DestroyTrash()
{
	GameManager::getInstance()->myplayer.setGold(100);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "������� �����ؾ���...";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(��� +100)";
}

void Event::PickUpTheGun()
{
	GameManager::getInstance()->myplayer.setDamage(10);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "� ���� �ֿ�!! �� ��� ���� �ʿ��� �ָ�!!";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(���ݷ� + 10)";
}

void Event::GetExp()
{
	GameManager::getInstance()->myplayer.SetExp(5);
	MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "���ʹ� ���θ� ���� ����ġ�� ȹ���߽��ϴ�!!";
	MoveCursor::getInstance()->GotoXY(50, 36); std::cout << "(����ġ + 5)";
}


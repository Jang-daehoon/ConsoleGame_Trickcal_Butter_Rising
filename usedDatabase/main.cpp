#include<iostream>
#include<string>
#include "PlayerCharacter.h"
#include"GameManager.h"

int main()
{
	//�ܼ� Size ����
	system("mode con: cols=100 lines=50");
	system("title ���� Ű���");	//�̸� ����
	GameManager::getInstance()->Prologue();

	Sleep(3000);
	system("mode con: cols=100 lines=50");
	system("cls");
	GameManager::getInstance()->StartScreen();

	GameManager::getInstance()->GameMenuSelect();

	while (GameManager::getInstance()->GetCurGameStage() < GameManager::getInstance()->GetLastGameStage())
	{
		GameManager::getInstance()->GrowthInterface();
		GameManager::getInstance()->SelectGrowEvent();

		//���� ���� �� ���� ���������� �̵�
		GameManager::getInstance()->BattleInterface();

		//�÷��̾� �й� �� ���� Ż��
		if (GameManager::getInstance()->myplayer.getCurHp() <= 0)
			break;
	};
	if (GameManager::getInstance()->myplayer.getCurHp() <= 0)
	{
		//�й� ����
		GameManager::getInstance()->LoseEndingScene();
	}
	else
	{
		std::cout << "���� ��Ƴ� ����!!";
		GameManager::getInstance()->MeetDiana();
		Sleep(5000);
		GameManager::getInstance()->VictoryEndingScene();
		Sleep(5000);
	}
}

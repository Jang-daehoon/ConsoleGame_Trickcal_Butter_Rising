#include<iostream>
#include<string>
#include "PlayerCharacter.h"
#include"GameManager.h"

int main()
{
	//�ܼ� Size ����
	system("mode con: cols=100 lines=50");
	system("title ���� Ű���");	//�̸� ����
	GameManager::getInstance()->StartScreen();
	GameManager::getInstance()->GameMenuSelect();

	while (GameManager::getInstance()->GetCurGameStage() < GameManager::getInstance()->GetLastGameStage())
	{
		GameManager::getInstance()->GrowthInterface();
		GameManager::getInstance()->SelectGrowEvent();

		//���� ���� �� ���� ���������� �̵�
		GameManager::getInstance()->BattleInterface();

		int a;
		std::cin >> a;

	}

	std::cout << "���� ��Ƴ� ����!!";
}
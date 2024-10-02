#include<iostream>
#include<string>
#include "PlayerCharacter.h"
#include"GameManager.h"

int main()
{
	//콘솔 Size 설정
	system("mode con: cols=100 lines=50");
	system("title 버터 키우기");	//이름 설정
	GameManager::getInstance()->StartScreen();
	GameManager::getInstance()->GameMenuSelect();

	while (GameManager::getInstance()->GetCurGameStage() < GameManager::getInstance()->GetLastGameStage())
	{
		GameManager::getInstance()->GrowthInterface();
		GameManager::getInstance()->SelectGrowEvent();

		//성장 종료 시 전투 스테이지로 이동
		GameManager::getInstance()->BattleInterface();

		int a;
		std::cin >> a;

	}

	std::cout << "보스 디아나 출현!!";
}
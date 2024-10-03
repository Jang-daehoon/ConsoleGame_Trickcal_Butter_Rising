#include<iostream>
#include<string>
#include "PlayerCharacter.h"
#include"GameManager.h"

int main()
{
	//콘솔 Size 설정
	system("mode con: cols=100 lines=50");
	system("title 버터 키우기");	//이름 설정
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

		//성장 종료 시 전투 스테이지로 이동
		GameManager::getInstance()->BattleInterface();

		//플레이어 패배 시 루프 탈출
		if (GameManager::getInstance()->myplayer.getCurHp() <= 0)
			break;
	};
	if (GameManager::getInstance()->myplayer.getCurHp() <= 0)
	{
		//패배 엔딩
		GameManager::getInstance()->LoseEndingScene();
	}
	else
	{
		std::cout << "보스 디아나 출현!!";
		GameManager::getInstance()->MeetDiana();
		Sleep(5000);
		GameManager::getInstance()->VictoryEndingScene();
		Sleep(5000);
	}
}

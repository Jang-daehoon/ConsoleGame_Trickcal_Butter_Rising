#include<iostream>
#include <cstdlib>
#include <ctime>   // 시간 시드를 설정하기 위한 라이브러리
#include <windows.h> // Sleep 함수 및 SetConsoleCursorPosition 사용을 위해 필요
#include <vector>
#include <random>  
#include"MoveCursor.h"
#include"PlayerCharacter.h"
#include"Event.h"
#include"Enemy.h"

#pragma once
class GameManager
{
private:
	static GameManager* instance;  // 싱글톤 인스턴스

	int curGameStage;
	int lastGameStage;
	int curBattleStage;
	int lastBattleStage;

	GameManager();

public:
	// 인스턴스를 얻기 위한 정적 메서드
	// static 함수로 선언
	static GameManager* getInstance();
	PlayerCharacter myplayer;
	Event randomEvent;
	Enemy newEnemy;

	void StartScreen();
	void GameExit();            // 게임 종료
	//시작 화면
	void GameMenuSelect();	//게임 로그인, 회원가입, 종료 값 받기
	void Prologue();

	//성장 화면
	void GrowthInterface();
	//성장 이벤트 선택
	void SelectGrowEvent();	//수정할 예정 gotoxy를 빼고 봐볼 것
	//성장 화면 내 버터의 대사(랜덤한 대사가 출력)
	void RandomDialog();

	//전투 화면
	void BattleInterface();
	void BattleSelect();

	//엔딩
	void LoseEndingScene();
	void VictoryEndingScene();
	void MeetDiana();
	//getter, setter
	int GetCurGameStage();
	int GetLastGameStage();
	int GetCurBattleStage();
	int GetLastBattleStage();

	void SetCurGameStage();
	void SetCurBattleStage();
};
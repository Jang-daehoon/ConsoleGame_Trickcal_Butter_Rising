#include<iostream>
#include <cstdlib>
#include <ctime>   // �ð� �õ带 �����ϱ� ���� ���̺귯��
#include <windows.h> // Sleep �Լ� �� SetConsoleCursorPosition ����� ���� �ʿ�
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
	static GameManager* instance;  // �̱��� �ν��Ͻ�

	int curGameStage;
	int lastGameStage;
	int curBattleStage;
	int lastBattleStage;

	GameManager();

public:
	// �ν��Ͻ��� ��� ���� ���� �޼���
	// static �Լ��� ����
	static GameManager* getInstance();
	PlayerCharacter myplayer;
	Event randomEvent;
	Enemy newEnemy;

	void StartScreen();
	void GameExit();            // ���� ����
	//���� ȭ��
	void GameMenuSelect();	//���� �α���, ȸ������, ���� �� �ޱ�
	void Prologue();

	//���� ȭ��
	void GrowthInterface();
	//���� �̺�Ʈ ����
	void SelectGrowEvent();	//������ ���� gotoxy�� ���� ���� ��
	//���� ȭ�� �� ������ ���(������ ��簡 ���)
	void RandomDialog();

	//���� ȭ��
	void BattleInterface();
	void BattleSelect();

	//����
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
#include <windows.h> // Sleep 함수 및 SetConsoleCursorPosition 사용을 위해 필요
#pragma once
class MoveCursor
{
	static MoveCursor* instance;  // 싱글톤 인스턴스

public:
	static MoveCursor* getInstance();
	void GotoXY(int x, int y);	// 화면 좌표 지정
};


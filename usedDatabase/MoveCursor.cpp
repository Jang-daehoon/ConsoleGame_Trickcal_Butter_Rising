#include "MoveCursor.h"

MoveCursor* MoveCursor::getInstance()
{
    // 인스턴스가 nullptr일 경우에만 새로 생성
    if (instance == nullptr)
    {
        instance = new MoveCursor();
    }
    return instance;
}

void MoveCursor::GotoXY(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // x, y 좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // pos 위치에 커서를 이동
}

MoveCursor* MoveCursor::instance = nullptr;
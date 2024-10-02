#include "MoveCursor.h"

MoveCursor* MoveCursor::getInstance()
{
    // �ν��Ͻ��� nullptr�� ��쿡�� ���� ����
    if (instance == nullptr)
    {
        instance = new MoveCursor();
    }
    return instance;
}

void MoveCursor::GotoXY(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // pos ��ġ�� Ŀ���� �̵�
}

MoveCursor* MoveCursor::instance = nullptr;
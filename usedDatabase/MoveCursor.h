#include <windows.h> // Sleep �Լ� �� SetConsoleCursorPosition ����� ���� �ʿ�
#pragma once
class MoveCursor
{
	static MoveCursor* instance;  // �̱��� �ν��Ͻ�

public:
	static MoveCursor* getInstance();
	void GotoXY(int x, int y);	// ȭ�� ��ǥ ����
};


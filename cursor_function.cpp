#include <windows.h>

void gotoXY(int x, int y) // Ŀ�� ��ġ �̵�
{
    COORD pos = { x ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int color) // ���� ����
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#include <windows.h>
#include "gClass.h";

void Window::Window_Set() {
	string temp;
	temp = "title " + title;
	system(temp.c_str()); // ���� ����

	temp = "mode concols=" + to_string(width) + " lines=" + to_string(height);
	system(temp.c_str()); // ũ�� ����

	/*
		Ŀ�� �����Ÿ� ����
	*/
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
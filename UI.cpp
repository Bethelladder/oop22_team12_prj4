#include "gClass.h";
#include <iostream>
#include <windows.h>
void gotoXY(int x, int y);
void setColor(int color);

UI::UI() {

	/*
		�ܼ�â ���� ����
	*/
	string temp;

	window_title = "OOP22 TEAM12 PROJECT4";
	window_width = 100;
	window_height = 30;

	temp = "title " + window_title;
	system(temp.c_str()); // ���� ����

	temp = "mode concols=" + to_string(window_width) + " lines=" + to_string(window_height);
	system(temp.c_str()); // ũ�� ����

	// Ŀ�� �����Ÿ� ����
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	/*
		���� �� UI ���� ����
	*/


	// Main_Box ����
	main_box_width = 80;
	main_box_height = 25;
	main_box_x = (window_width - main_box_width) / 2; // Main_Box�� Window�� �߰��� ������ �Ѵ�
	main_box_y = 1;
	Draw_Main_Box();

	// Typing_Box ����
	typing_box_width = 26 ;
	typing_box_height = 5;
	typing_box_x = (main_box_width - typing_box_width) / 2; // Typing_Box�� Main_Box�� �߰��� ������ �Ѵ�
	typing_box_y = 18;
	Draw_Typing_Box();
}

void UI::Draw_Main_Box() {
	for (int i = 0; i < main_box_height; i++) {
		for (int j = 0; j < main_box_width; j++) {
			gotoXY(main_box_x + j, main_box_y + i);
			if (j == 0 && i == 0) {
				cout <<"��";
			}
			else if (j == main_box_width - 1 && i == 0) {
				cout << "��";
			}
			else if (j == 0 && i == main_box_height - 1) {
				cout << "��";
			}
			else if (j == main_box_width - 1 && i == main_box_height - 1) {
				cout << "��";
			}
			else if (i == 0 || i == main_box_height - 1) {
				cout << "��";
			}
			else if (j == 0 || j == main_box_width - 1) {
				cout << "��";
			}
		}
	}
}

void UI::Draw_Typing_Box() {
	for (int i = 0; i < typing_box_height; i++) {
		for (int j = 0; j < typing_box_width; j++) {
			gotoXY(main_box_x + typing_box_x + j, main_box_y + typing_box_y + i);
			if (j == 0 && i == 0) {
				printf("��");
			}
			else if (j == typing_box_width - 1 && i == 0) {
				printf("��");
			}
			else if (j == 0 && i == typing_box_height - 1) {
				printf("��");
			}
			else if (j == typing_box_width - 1 && i == typing_box_height - 1) {
				printf("��");
			}
			else if (i == 0 || i == typing_box_height - 1) {
				printf("��");
			}
			else if (j == 0 || j == typing_box_width - 1) {
				printf("��");
			}
		}
	}
}
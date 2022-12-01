#include "gClass.h";
#include <iostream>

void GameManager::Init() {
	word_manager.add_falling_word(ui.get_main_box_width()); // �������� �ܾ� �߰�

	vector<Word>& falling_word_list = word_manager.get_falling_word_list();
	falling_word_list[0].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y()); // ó�� ������ �ܾ� �׸���
}

void gotoXY(int, int);
void GameManager::Update() {
	vector<Word>& falling_word_list = word_manager.get_falling_word_list();

	system_time = clock(); // �ý��� �ð� ����

	for (int i = 0; i < falling_word_list.size(); i++) {
		if (system_time - falling_word_list[i].get_last_update_time() >= falling_word_list[i].get_update_time_interval()) {
			falling_word_list[i].Word_Erase(ui.get_main_box_x(), ui.get_main_box_y());
			// �ܾ ���� ���� ���ο� ������ �������
			if (falling_word_list[i].get_y() >= ui.get_game_over_line_y()) {
				falling_word_list.erase(falling_word_list.begin() + i);
				i--;
				continue;
			}
			falling_word_list[i].set_y(falling_word_list[i].get_y() + falling_word_list[i].get_speed());
			falling_word_list[i].set_last_update_time(system_time);
			falling_word_list[i].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y());
		} // ������ �ܾ �ڽ��� update_time_interval �Ŀ� ��ǥ�� ���ŵȴ�
	}
	if (system_time - word_manager.get_last_word_birth_time() >= word_manager.get_birth_time_interval()) {
		word_manager.add_falling_word(ui.get_main_box_width()); // �������� �ܾ� �߰�
		falling_word_list[falling_word_list.size() - 1].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y()); // ó�� ������ �ܾ� �׸���
		word_manager.set_last_word_birth_time(system_time);
	}	// birth_time_interval �Ŀ� �ܾ �����ȴ�
}

void GameManager::FPS()
{
	clock_t FPSOld = clock();
	clock_t FPSCurr;

	while (true)
	{
		FPSCurr = clock();

		if (FPSCurr - FPSOld > 10)
		{
			break;
		}
	}
}
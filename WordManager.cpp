#include "gClass.h"
#include <fstream>
#include <random>
#include <vector>

WordManager::WordManager() {
	ifstream input_stream;
	input_stream.open("wordlist3000.txt");
	if (input_stream.fail()) {
		return;
	}
	char temp[100]; //������ ū ����, ���Ͽ��� ���پ� �޾ƿö� �ӽ÷� ���
	while (input_stream.getline(temp, 100)) {
		load_word_list.push_back(string(temp));
	}

	input_stream.close();

	last_word_birth_time = clock();
	birth_time_interval = (clock_t)1000;
}

void WordManager::add_falling_word(int main_box_width) { // �� �޼ҵ带 �����ϸ� �����ܾ� �ϳ��� �����ͼ� falling_word_list�� �߰���
	random_device  rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis_word(0, 3000 - 1);
	string selected_word = load_word_list[dis_word(gen)];

	uniform_int_distribution<int> dis_x(1, main_box_width - (int)selected_word.size() - 1); // �ܾ��� ���� x��ǥ�� ���Ѵ�. Main Box ������ �������ʰ� ���Ѵ�.
	int selected_x = dis_x(gen);

	uniform_int_distribution<clock_t> dis_update_interval(500, 500); // �ܾ� ������Ʈ �ð� ������ �������� ���Ѵ�.
																	   // �׷��� �� �ܾ��� �ӵ��� �ٸ��� �ܾ ��ġ�� ������ �����
																	   // ���߿� ��������� ���� �̸��� �ܾ ���� ��������� ���� �̸���
																	   // �ܾ���� �߿� ���� �� �� �ؿ� �ִ� �ܾ� ���ֵ��� �����ؾ���
																	   // �׷��� �ϴ� �ӵ��� �����ϴٰ� ����
	clock_t selected_interval = dis_update_interval(gen);
	
	falling_word_list.push_back(Word(selected_word, selected_x, 1, 1, selected_interval));

}
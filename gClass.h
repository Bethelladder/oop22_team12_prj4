#include <string>
//#include <time.h>
#include <vector>
using namespace std;

/*
   ���� ��, setColor(int color) �Լ��� ���ڷ� ���ȴ�.
*/
#define RED 4 
#define ORANGE 12
#define YELLOW 14
#define GREEN 10
#define CYAN 11
#define BLUE 9
#define PURPLE 13
#define WHITE 15
#define GRAY 8
#define DARK_YELLOW 6
#define DARK_BLUE 1

class UI {
public:
	UI();

	//int get_main_box_width() { return main_box_width; }
	int get_main_box_x() { return main_box_x; }
	int get_main_box_y() { return main_box_y; }

	//void set_main_box_width(int w) { main_box_width = w; }
	//void set_main_box_height(int h) { main_box_height = h; }
	//void set_main_box_x(int x) { main_box_x = x; }
	//void set_main_box_y(int y) { main_box_y = y; }

	//int get_typing_box_width() { return typing_box_width; }

	//void set_typing_box_width(int w) { typing_box_width = w; }
	//void set_typing_box_height(int h) { typing_box_height = h; }
	//void set_typing_box_x(int x) { typing_box_x = x; }
	//void set_typing_box_y(int y) { typing_box_y = y; }

	void Draw_Main_Box();
	void Draw_Typing_Box();

private:
	string window_title; // �ܼ�â ����
	int window_width; // �ܼ�â �ʺ�
	int window_height; // �ܼ�â ũ��

	int main_box_width; // ���� ���� ���� �ʺ�
	int main_box_height; // ���� ���� ���� ����
	int main_box_x; // ���� ���� ���� ���ʿ��� ���� X��ǥ
	int main_box_y; // ���� ���� ���� ���ʿ��� ���� Y��ǥ

	int typing_box_width; // Ÿ���� ���� �ʺ�
	int typing_box_height; // Ÿ���� ���� ����
	int typing_box_x; // Ÿ���� ������ ���� ���� ���� ���ʿ��� ���� X��ǥ
	int typing_box_y; // Ÿ���� ������ ���� ���� ���� �Ʒ��ʿ��� ���� Y��ǥ

};


class Word {
public:
	Word(string name, int x, int y, int s);

	string get_name() { return name; }
	int get_x(){ return x; }
	int get_y() { return y; }
	int get_speed() { return speed; }

	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	void set_speed(int s) { speed = s; }

	void Word_Draw(int main_box_x, int main_box_y);
	void Word_Erase(int main_box_x, int main_box_y);

private:
	string name;
	int x;
	int y;
	int speed;
};

class WordManager {
public:
	vector<Word>& get_current_word_list() { return current_word_list;  }

private:
	vector<Word> dictionary;
	vector<Word> current_word_list;
};

class GameManager {
public:
	void Init(); // ���� ���۽� �ʱ� ���� ����
	void Update(); // �����Ӹ��� ���� Update
	void FPS(/*clock_t* FPSCurr, clock_t* FPSOld*/); // Frame Per Second ����
private:
	//Window window;
	UI ui;
	WordManager word_manager;
};
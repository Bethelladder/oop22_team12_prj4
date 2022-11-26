#include <string>
#include <time.h>
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

	int get_main_box_width() { return main_box_width; }

	void set_main_box_width(int w) { main_box_width = w; }
	void set_main_box_height(int h) { main_box_height = h; }
	void set_main_box_x(int x) { main_box_x = x; }
	void set_main_box_y(int y) { main_box_y = y; }

	int get_typing_box_width() { return typing_box_width; }

	void set_typing_box_width(int w) { typing_box_width = w; }
	void set_typing_box_height(int h) { typing_box_height = h; }
	void set_typing_box_x(int x) { typing_box_x = x; }
	void set_typing_box_y(int y) { typing_box_y = y; }

	void Draw_Main_Box();
	void Draw_Typing_Box();

private:
	int main_box_width; // ���� ���� ���� �ʺ�
	int main_box_height; // ���� ���� ���� ����
	int main_box_x; // ���� ���� ���� ���ʿ��� ���� X��ǥ
	int main_box_y; // ���� ���� ���� ���ʿ��� ���� Y��ǥ

	int typing_box_width; // Ÿ���� ���� �ʺ�
	int typing_box_height; // Ÿ���� ���� ����
	int typing_box_x; // Ÿ���� ������ ���� ���� ���� ���ʿ��� ���� X��ǥ
	int typing_box_y; // Ÿ���� ������ ���� ���� ���� �Ʒ��ʿ��� ���� Y��ǥ

};

class Window {
public:

	int get_width() { return width;  }

	void set_width(int w) { width = w; }
	void set_height(int h) { height = h; }
	void set_title(string s) { title = s; }

	void Window_Set(); // ������ â �⺻ ����
private:
	string title; // �ܼ�â ����
	int width; // �ܼ�â �ʺ�
	int height; // �ܼ�â ũ��
};

class GameManager {
public:
	void Init(); // ���� ���۽� �ʱ� ���� ����
	void Update(); // �����Ӹ��� ���� Update
	void FPS(clock_t* FPSCurr, clock_t* FPSOld); // Frame Per Second ����
private:
	Window window;
	UI ui;
};
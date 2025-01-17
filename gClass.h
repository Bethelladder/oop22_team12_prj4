#include <string>
#include <vector>
#include <time.h>
using namespace std;

/*
   색깔 값, setColor(int color) 함수의 인자로 사용된다.
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


class Word {
public:
	Word(string name, int x = 0, int y = 0, int s = 0, clock_t update_time_interval = 0);

	string get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }
	int get_speed() { return speed; }

	clock_t get_last_update_time() { return last_update_time; }
	clock_t get_update_time_interval() { return update_time_interval; }

	void set_last_update_time(clock_t t) { last_update_time = t; }
	void set_update_time_interval(clock_t t) { update_time_interval = t; }


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
	clock_t last_update_time; // 단어가 마지막으로 업데이트된 시각
	clock_t update_time_interval; // 단어 업데이트된 시간 간격
};

class WordManager {
public:
	WordManager();

	vector<Word>& get_falling_word_list() { return falling_word_list; }
	clock_t get_last_word_birth_time() { return last_word_birth_time; }
	clock_t get_birth_time_interval() { return birth_time_interval; }

	void set_last_word_birth_time(clock_t t) { last_word_birth_time = t; }
	void set_birth_time_interval(clock_t t) { birth_time_interval = t; }
	void add_falling_word(int main_box_width); // 이 메소드를 실행하면 랜덤단어 하나만 가져와서 falling_word_list에 추가됨


private:
	vector<string> load_word_list;
	vector<Word> falling_word_list;
	int total_word_cnt;

	clock_t last_word_birth_time; // 단어가 마지막으로 생성된 시각
	clock_t birth_time_interval; // 단어 생성 시간 간격
};

class UI {
public:
	UI();

	int get_main_box_width() { return main_box_width; }
	int get_main_box_x() { return main_box_x; }
	int get_main_box_y() { return main_box_y; }
	int get_game_over_line_y() { return game_over_line_y; }

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

	void keyboardEvent(vector<Word>& falling_word_list);

private:
	string window_title; // 콘솔창 제목
	int window_width; // 콘솔창 너비
	int window_height; // 콘솔창 높이

	int main_box_width; // 메인 게임 공간 너비
	int main_box_height; // 메인 게임 공간 높이
	int main_box_x; // 메인 게임 공간 왼쪽에서 시작 X좌표
	int main_box_y; // 메인 게임 공간 위쪽에서 시작 Y좌표

	int typing_box_width; // 타이핑 공간 너비
	int typing_box_height; // 타이핑 공간 높이
	int typing_box_x; // 타이핑 공간의 메인 게임 공간 왼쪽에서 시작 X좌표
	int typing_box_y; // 타이핑 공간의 메인 게임 공간 아래쪽에서 시작 Y좌표

	int game_over_line_y; // 단어가 닿으면 게임이 끝나는 y좌표

	string typing_str; // 현재 입력한 문자열
};

class GameManager {
public:
	void Init(); // 게임 시작시 초기 정보 설정
	void Update(); // 프레임마다 정보 Update
	void FPS(); // Frame Per Second 조절
private:
	UI ui;
	WordManager word_manager;
	clock_t system_time; // 게임 시작하고 경과된 시간
};
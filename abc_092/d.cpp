#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

constexpr char WHITE='.';
constexpr char BLACK='#';

class Board{
public:
	Board(){
		for(int i=0; i<MAX_SIZE; ++i){
			fill(_data[i].begin(), _data[i].end(), i < MAX_SIZE/2 ? BLACK : WHITE);
		}
	}

	void add_points(char color, int num){
		int l_max_num = (MAX_SIZE + 1)/2;
		for(int i=0; i<num; ++i){
			int l = (i/l_max_num)*2;
			int r = (i%l_max_num)*2;
			switch(color){
			case WHITE:
				_data[l][r] = WHITE;
				break;
			case BLACK:
				_data[MAX_SIZE - l - 1][r] = BLACK;
				break;
			}
		}
	}

	void output(){
		cout << 100 << " " << 100 << endl;
		for(int l=0; l<MAX_SIZE; ++l){
			for(int r=0; r<MAX_SIZE; ++r){
				cout << _data[l][r];
			}
			cout << endl;
		}
	}
private:
	constexpr static int MAX_SIZE=100;
	array<array<char, MAX_SIZE>, MAX_SIZE> _data;
};

constexpr int Board::MAX_SIZE;

int main() {
	int A, B;
	cin >> A >> B;
	Board board;
	board.add_points(WHITE, A - 1);
	board.add_points(BLACK, B - 1);
	board.output();
}

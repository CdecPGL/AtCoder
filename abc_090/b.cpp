// Score: 200/200

#include <iostream>

using namespace std;

int main() {
	std::string input;
	cin >> input;
	int A{ atoi(input.c_str()) };
	cin >> input;
	int B{ atoi(input.c_str()) };
	int count = 0;
	for (int i = A; i <= B; ++i) {
		int d5 = i / 10000;
		int d4 = (i / 1000) % 10;
		int d2 = (i / 10) % 10;
		int d1 = i % 10;
		if (d5 == d1 && d4 == d2) {
			++count;
		}
	}
	cout << count;
}
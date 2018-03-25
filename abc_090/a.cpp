// Score: 100/100

#include <iostream>
#include <string>

using namespace std;

int main() {
	for (int i = 0; i < 3; ++i) {
		std::string input;
		cin >> input;
		cout << input[i];
	}
}
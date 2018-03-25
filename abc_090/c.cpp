#include <iostream>

using namespace std;

int main() {
	std::string input;
	int N, M;
	cin >> N >> M;
	int a{ min(N, M) };
	int b{ max(N, M) };
	if (a == 1) {
		cout << (b == 1 ? 1 : b - 2) << endl;
	}
	else if (a == 2 || b == 2) {
		cout << 0 << endl;
	}
	else {
		cout << (int64_t)(a - 2)*(b - 2) << endl;
	}
}
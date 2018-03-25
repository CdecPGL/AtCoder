// Score: 200/200

#include <iostream>

using namespace std;

int main() {
	int N, D, X;
	cin >> N >> D >> X;
	int choco_num = X;
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		choco_num += (D-1)/A + 1;
	}
	cout << choco_num;
}

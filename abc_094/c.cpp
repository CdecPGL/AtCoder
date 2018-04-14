// Score: 300/300

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> Xs(N);
	vector<int> Xss(N);
	for (int i = 0; i < N; ++i) {
		cin >> Xs[i];
		Xss[i] = Xs[i];
	}
	sort(Xss.begin(), Xss.end());
	int B1(Xss[N / 2 - 1]), B2(Xss[N / 2]);
	for (const auto &X : Xs) {
		cout << ((X <= B1) ? B2 : B1) << endl;
	}
}

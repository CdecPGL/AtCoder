// Score: 0/500(Not Submit)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	unsigned int N;
	cin >> N;
	vector<uint32_t> a{ N }, b{ N };
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	uint32_t res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == 0 && j == 0) {
				res = a[i] + b[j];
			}
			else {
				res ^= a[i] + b[j];
			}
		}
	}
	cout << res;
}

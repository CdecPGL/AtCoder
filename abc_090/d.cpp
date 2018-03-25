// Score: 0/400(TLE)

#include <iostream>

using namespace std;

int main() {
	std::string input;
	int N, K;
	cin >> N >> K;
	
	int count = 0;
	for (int k = K; k < N; ++k) {
		for (int b = k + 1; b <= N; ++b) {
			int c = N / b;
			if (c*b + k <= N) {
				++c;
			}
			count += c;
		}
	}
	if (K == 0) { 
		count -= N;
	}
	cout << count;
}
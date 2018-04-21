// Score: 200/200

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int min_m = 10000;
	for(int i=0;i<N;++i){
		int m;
		cin >> m;
		X -= m;
		min_m = min(m, min_m);
	}
	cout << (N+X/min_m);
}

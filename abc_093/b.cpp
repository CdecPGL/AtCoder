//Score: 200/200

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	uint64_t A, B, K;
	cin >> A >> B >> K;
	for(auto i=A; i<=min(A+K-1, B); ++i){
		cout << i << endl;
	}
	for(auto i=max(B-K+1, A+K); i<=B; ++i){
		cout << i << endl;
	}
	
}

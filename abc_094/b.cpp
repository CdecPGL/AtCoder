//Score: 200/200

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	int left_fee = 0, right_fee = 0;
	for(int i=0; i<M; ++i){
		int A;
		cin >> A;
		if(A<X){
			++left_fee;
		}else if(A>X){
			++right_fee;
		}
	}
	cout << min(left_fee, right_fee);
}

// Score: 300/300

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> rel_pos_list(N+1);
	int prev_pos = 0;
	int fee_sum = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		rel_pos_list[i] = A - prev_pos;
		fee_sum += abs(A - prev_pos);
		prev_pos = A;
	}
	rel_pos_list[N] = -prev_pos;
	fee_sum += abs(prev_pos);
	for(int i=0; i<N; ++i){
		cout << fee_sum - (abs(rel_pos_list[i]) + abs(rel_pos_list[i+1])) + abs(rel_pos_list[i]+rel_pos_list[i+1]) << endl;
	}
}

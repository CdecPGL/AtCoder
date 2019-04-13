// Score: 未提出/400

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	string S;
	cin >> N >> K >> S;

	if (K*2+1 >= N){
		cout << N;
		return 0;
	}

	auto pc = ' ';
	vector<int> counts;
	auto count = 0;
	for(auto c : S){
		++count;
		if(pc != c){
			counts.push_back(count);
			count = 0;
		}
	}
	if(count > 0){
		counts.push_back(count);
	}

	auto s = 0;
	auto fp = 0;
	auto tc = 0;
	for(auto i=0u;i<counts.size();++i){
		++s;
		if(s > K*2+1){
			tc -= counts[fp];
			++fp;
			--s;
		}

		tc += counts[i];
	}

	cout << tc;
}
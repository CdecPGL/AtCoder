// Not Submit

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

set<int> calc(int num, int tar){
	set<int> ret;
	for(int i=tar+1; i<=(num-tar); ++i){
		int n_num = num % i;
		if(n_num==tar){
			return {i};
		}else{
			auto n_ret = calc(n_num, tar);
			if(n_ret.size()){
				n_ret.insert(i);
				return n_ret;
			}
		}
	}
	return {};
}

int main() {
	int N;
	cin >> N;
	vector<int> an(N), bn(N);
	for(int i=0; i<N; ++i){
		cin >> an[i];
	}
	for(int i=0; i<N; ++i){
		cin >> bn[i];
	}
	if(an==bn){
		cout << 0;
		return 0;
	}
	set<int> ks;
	for(int i=0; i<N; ++i){
		auto ret = calc(an[i], bn[i]);
		set_union(ks.begin(), ks.end(), ret.begin(), ret.end(), inserter(ks, ks.begin()));
	}
	uint64_t res = 0;
	for(const auto& k : ks){
		res += (2llu << (k-1));
		cerr << k << ", ";
	}
	cerr <<  endl;
	if(res){
		cout << res;
	}else{
		cout << -1;
	}
}

// 400/400

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> as(n);
	for(int i=0; i<n; ++i){
		cin >> as[i];
	}
	sort(as.begin(), as.end());
	int ai = *(--as.end());
	int aj=0;
	double min_diff=2000000000;
	for(auto it = as.rbegin(); it != as.rend(); ++it){
		int a = *it;
		double diff = abs(a-ai/2.0);
		if(a != ai && diff < min_diff){
			min_diff = diff;
			aj = a;
		} else if(a < ai/2.0){
			break;
		}
	}
	cout << ai << " " << aj;
}

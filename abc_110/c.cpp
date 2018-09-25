// Score: 300/300

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	array<int, 26> dist_s, dist_t;
	fill(dist_s.begin(), dist_s.end(), 0);
	fill(dist_t.begin(), dist_t.end(), 0);

	string S, T;
	cin >> S >> T;

	for (int i=0;i<S.size();++i){
		++dist_s[S[i]-'a'];
		++dist_t[T[i]-'a'];
	}
	sort(dist_s.begin(), dist_s.end());
	sort(dist_t.begin(), dist_t.end());

	cout << (equal(dist_s.begin(), dist_s.end(), dist_t.begin()) ? "Yes" : "No");
}

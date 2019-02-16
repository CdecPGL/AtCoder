// Score: 200/200

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> like_count(M);
	for (int n = 0; n < N; ++n)
	{
		int K;
		cin >> K;
		for (int k = 0; k < K; ++k)
		{
			int A;
			cin >> A;
			++like_count[A - 1];
		}
	}
	cout << count_if(like_count.begin(), like_count.end(), [N](int c) { return c == N; });
}

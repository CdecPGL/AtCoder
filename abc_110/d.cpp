// Score: 未提出/400

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	list<int> nums;
	for (int i = 2; i <= sqrt(M); ++i)
	{
		int cnt = 0;
		while (M % i == 0)
		{
			M /= i;
			++cnt;
		}
		nums.push_back(cnt);
	}
	int C = 1;


	int ret = 1;
	for (auto i = 2; i <= N; ++i)
	{
		ret = (ret * i) % 1000000007;
	}
	int ret2 = 1;
	for (int i = 0; i < C; ++i)
	{
		ret2 = (ret2 * ret) % 1000000007;
	}
	cout << ret2;
}

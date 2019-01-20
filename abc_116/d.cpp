// Score: 未提出/400

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<uint64_t> ts(N), ds(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> ts[i] >> ds[i];
	}
	unordered_set<uint64_t> eaten_t;
	uint64_t sum_d = 0;
	for (int k = 0; k < K; ++k)
	{
		int max_i = 0;
		uint64_t max_score = 0;
		for (int i = 0; i < N; ++i)
		{
			int score;
			if(ds[i]==0){
				score = 0;
			}
			else if (eaten_t.find(ts[i]) == eaten_t.end())
			{
				score = (eaten_t.size() + 1) * (eaten_t.size() + 1) + sum_d + ds[i];
			}
			else
			{
				score = eaten_t.size() * eaten_t.size() + sum_d + ds[i];
			}
			if (score > max_score)
			{
				max_score = score;
				max_i = i;
			}
		}
		// cout << max_i << endl;
		eaten_t.insert(ts[max_i]);
		sum_d += ds[max_i];
		ds[max_i] = 0;
	}
	cout << eaten_t.size() * eaten_t.size() + sum_d;
}

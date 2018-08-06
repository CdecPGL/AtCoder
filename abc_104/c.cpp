// Score: 0/300

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int D, G_100;
	cin >> D >> G_100;
	G_100 /= 100;
	vector<list<int>> score_list(D);
	int score = 0;
	int count = 0;
	int min_count = 99999999;
	for (int i = 0; i < D; ++i)
	{
		int p, c_100;
		cin >> p >> c_100;
		c_100 /= 100;
		int total_score = (i + 1) * p + c_100;
		score += total_score;
		if(total_score >= G_100){
			min_count = min(min_count, p);
		}
		count += p;
		for (int j = 0; j < p - 1; ++j)
		{
			score_list[i].push_back(i + 1);
		}
		score_list[i].push_back(i + 1 + c_100);
	}
	while (true)
	{
		auto gap = score - G_100;
		int min_score = 1000000;
		int min_idx = -1;
		for (int i = 0; i < D; ++i)
		{
			if (score_list[i].size() > 0)
			{
				auto s = (*(--score_list[i].end()));
				if (s < min_score)
				{
					min_score = s;
					min_idx = i;
				}
			}
		}
		score_list[min_idx].pop_back();
		if (gap < min_score)
		{
			cout << min(count, min_count);
			return 0;
		}
		else
		{
			score -= min_score;
			--count;
		}
	}
}

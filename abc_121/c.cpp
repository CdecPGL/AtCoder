// Score: 300/300

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	map<int64_t, int> value_map;
	for (int n = 0; n < N; ++n)
	{
		int64_t A;
		int B;
		cin >> A >> B;
		if (value_map.find(A) == value_map.end())
		{
			value_map.emplace(A, B);
		}
		else
		{
			value_map[A] += B;
		}
	}
	int64_t total_value = 0;
	int rest = M;
	for (auto it = value_map.begin(); it != value_map.end(); ++it)
	{
		if (it->second < rest)
		{
			rest -= it->second;
			total_value += it->first * it->second;
		}
		else
		{
			total_value += it->first * rest;
			break;
		}
	}
	cout << total_value;
}

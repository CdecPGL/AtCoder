// Score: 200/200

#include <iostream>
#include <unordered_set>

using namespace std;

int func(int n)
{
	if (n % 2)
	{
		return 3 * n + 1;
	}
	else
	{
		return n / 2;
	}
}

int main()
{
	int s;
	cin >> s;
	unordered_set<int> history;
	for (int i = 1;i<1000000; ++i)
	{
		history.insert(s);
		s = func(s);
		if (history.find(s) != history.end())
		{
			cout << i+1;
			break;
		}
	}
}

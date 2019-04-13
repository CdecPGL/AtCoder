// Score: 300/300

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string S;
	cin >> S;
	int odd_0 = 0, odd_1 = 0, even_0 = 0, even_1 = 0;
	for (auto i = 0u; i < S.size(); ++i)
	{
		if (i % 2)
		{
			if (S[i] == '0')
			{
				++odd_0;
			}
			else
			{
				++odd_1;
			}
		}
		else
		{
			if (S[i] == '0')
			{
				++even_0;
			}
			else
			{
				++even_1;
			}
		}
	}

	cout << min(odd_1 + even_0, odd_0 + even_1);
}

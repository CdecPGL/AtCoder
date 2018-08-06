// Score: 200/200

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S;
	cin >> S;
	int c_count = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		if (i == 0)
		{
			if (S[i] != 'A')
			{
				cout << "WA";
				return 0;
			}
		}
		else if (2 <= i && i <= S.size() - 2)
		{
			if (S[i] == 'C')
			{
				++c_count;
			}
			else if ('A' <= S[i] && S[i] <= 'Z')
			{
				cout << "WA";
				return 0;
			}
		}
		else if ('A' <= S[i] && S[i] <= 'Z')
		{
			cout << "WA";
			return 0;
		}
	}
	if (c_count != 1)
	{
		cout << "WA";
		return 0;
	}
	cout << "AC";
}

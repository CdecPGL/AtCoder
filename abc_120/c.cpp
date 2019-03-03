// Score: 300/300

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string S;
	cin >> S;
	int r{0}, b{0};
	for (auto c : S)
	{
		if (c == '0')
		{
			++r;
		}
		else
		{
			++b;
		}
	}
	cout << 2 * min(r, b);
}

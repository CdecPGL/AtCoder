// Score: 200/200

#include <iostream>
#include <cmath>

using namespace std;

bool is_beki(int num)
{
	if (num == 1)
	{
		return true;
	}
	for (int i = 2; i <= sqrt(num); ++i)
	{
		auto v = log(num) / log(i);
		if (abs(v - round(v)) < 0.00001)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int X;
	cin >> X;
	for (int i = X; i >= 1; --i)
	{
		if (is_beki(i))
		{
			cout << i;
			break;
		}
	}
}

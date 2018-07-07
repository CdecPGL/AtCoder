// Score: 0/300

#include <iostream>

using namespace std;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	double beauty = (double)(m - 1) / n;
	if (d > n / 2)
	{
		beauty *= (double)(n - 2 * d) / n;
	}
	else if (d > 0)
	{
		beauty *= 2.0 * (double)(n - d) / n;
	}
	cout << beauty;
}

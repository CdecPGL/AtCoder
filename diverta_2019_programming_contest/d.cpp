// Score: 500/500

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	uint64_t N;
	cin >> N;
	uint64_t sum = 0;
	for (uint64_t a = 1; a < sqrt(N); ++a)
	{
		if ((N - a) % a == 0)
		{
			auto m = (N - a) / a;
			if (m > a)
			{
				sum += m;
			}
		}
	}

	cout << sum;
}
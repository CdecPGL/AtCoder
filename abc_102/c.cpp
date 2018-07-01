// Score: ?/300(未提出)

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int min, max;
	uint64_t x_sum = 0;
	std::vector<int> As(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> As[i];
		int x = As[i] - i - 1;
		x_sum += x;
	}
	int b =  round((double)x_sum / (double)N);
	uint32_t kanasisa = 0;
	for (int i = 0; i < N; ++i)
	{
		kanasisa += abs(As[i] - b - i - 1);
	}

	cout << kanasisa;
}

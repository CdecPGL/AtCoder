// Score: 200/200

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;
	int prev_col = -1;
	int continue_count = 1;
	for (int i = 0; i < N; ++i)
	{
		int col;
		cin >> col;
		if (prev_col >= 0 && prev_col == col)
		{
			++continue_count;
		}
		else
		{
			count += continue_count / 2;
			continue_count = 1;
		}
		prev_col = col;
	}
	count += continue_count / 2;
	cout << count;
}

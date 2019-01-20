// Score: 300/300

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<bool> flags(N, false);
	int mizuyari = 0;
	for (int i = 0; i < N; ++i)
	{
		int h;
		cin >> h;
		for (int j = 0; j < 100; ++j)
		{
			if (h >= j + 1)
			{
				if (!flags[j])
				{
					++mizuyari;
					flags[j] = true;
				}
			}
			else
			{
				flags[j] = false;
			}
		}
	}

	cout << mizuyari;
}

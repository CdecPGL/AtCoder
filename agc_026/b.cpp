// not submit, TLE

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		unordered_set<int64_t> his;
		int64_t A, B, C, D;
		cin >> A >> B >> C >> D;
		bool no = false;
		while (true)
		{
			if (A < B)
			{
				no = true;
				break;
			}
			if (C < B)
			{
				int64_t dec_b = ((A - B) / B + 1) * B;
				if (A - dec_b > C)
				{
					no = true;
					break;
				}
			}
			int64_t dec_c_idx = (A - C - 1) / B + 1;
			int64_t dec_c = dec_c_idx < 1 ? B : dec_c_idx * B;
			A -= dec_c;
			A = A < 0 ? 0 : A;
			if (his.find(A) != his.end())
			{
				break;
			}
			his.insert(A);
			if (A <= C)
			{
				A += D;
			}
		}
		cout << (no ? "No" : "Yes") << endl;
	}
}

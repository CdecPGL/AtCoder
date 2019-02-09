// Score: 400/400

#include <iostream>

using namespace std;

template <typename T, typename U>
T max(T l, U r)
{
	return (l < r) ? r : l;
}

int main()
{
	int64_t K, A, B;
	cin >> K >> A >> B;
	if (A + 2 >= B || K < (A + 1))
	{
		cout << K + 1;
	}
	else {
		int64_t n = (K - (A + 1)) / 2;
		cout << B + n * (B - A) + (K - (A + 1)) % 2;
	}
}

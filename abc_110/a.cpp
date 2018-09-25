// Score: 100/100

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << max({
		A * 10 + B + C,
		A * 10 + C + B,
		B * 10 + A + C,
		B * 10 + C + A,
		C * 10 + A + B,
		C * 10 + B + A,
		A + B * 10 + C,
		A + C * 10 + B,
		B + A * 10 + C,
		B + C * 10 + A,
		C + A * 10 + B,
		C + B * 10 + A,
	});
}

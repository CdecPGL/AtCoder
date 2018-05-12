// Score: 100/100

#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << ((abs(a - c) <= d || ((a - b) * (b - c) > 0 && abs(a - b) <= d && abs(c - b) <= d)) ? "Yes" : "No");
}

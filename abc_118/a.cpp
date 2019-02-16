// Score: 100/100

#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	cout << (B % A ? B - A : B + A);
}

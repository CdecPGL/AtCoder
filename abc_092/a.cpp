// Score: 100/100

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << min(A, B) + min(C, D);
}

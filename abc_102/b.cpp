// Score: 0/200

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int min, max;
	for(int i=0;i<N;++i){
		int A;
		cin >> A;
		min = std::min(A,min);
		max = std::max(A, max);
	}
	cout << max - min;
}

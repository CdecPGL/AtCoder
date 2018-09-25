// Score: 200/200

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	int Z = X+1;
	for (int i = 0; i < N; ++i)
	{
		int xi;
		cin >> xi;
		Z = max(xi+1, Z);
	}
	if(Z > Y){
		cout << "War";
		return 0;
	}
	for (int i = 0; i < M; ++i)
	{
		int yi;
		cin >> yi;
		if(yi< Z){
			cout << "War";
			return 0;
		}
	}
	cout << "No War";
}

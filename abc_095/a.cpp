// Score: 100/100

#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	int value = 700;
	for(const auto& c : S){
		if(c=='o'){
			value += 100;
		}
	}
	cout << value;
}

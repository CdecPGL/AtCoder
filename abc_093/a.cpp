// Score: 100/100

#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.find_first_of('a') != string::npos && S.find_first_of('b') != string::npos && S.find_first_of('c') != string::npos){
		cout << "Yes";
	}else{
		cout << "No";
	}
}

// Not Submit

#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num){
	if(num<=1){return false;}
	for(int i=2; i<(int)sqrt(num); ++i){
		if(num!=i && num%2==0){
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int> ret;
	if(N==3){
		cout << "2 5 63";
		return 0;
	}

	vector<int> primes;
	for(int i=2; i<30000;++i){
		if(is_prime(i)){
			primes.push_back(i);
		}
	}

	int N;
	
}

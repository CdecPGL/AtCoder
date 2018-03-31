// Score: 300/300

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string S;
	cin >> S;
	set<char> char_set;
	char last = 'a' - 1;
	while(true){
		for(char c=last+1; c<='z';++c){
			char_set.insert(c);
		}
		for(const auto& c : S){
			char_set.erase(c);
		}
		if(char_set.size()){
			cout << S + *char_set.begin();
			return 0;
		}else{
			if(S.size()==0){
				break;
			}
			last = *(S.end() - 1);
			S = S.substr(0, S.size() - 1);
		}
	}
	cout << -1;
}

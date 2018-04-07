// Score: 300/300

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
	array<int, 3> nums;
	cin >> nums[0] >> nums[1] >> nums[2];
	int count=0;
	while(!all_of(nums.begin(), nums.end(), [&nums](int n){return n==nums[0];})){
		++count;
		auto max_it = max_element(nums.begin(), nums.end());
		bool two_max=false;
		for(auto it=nums.begin(); it!=nums.end();++it){
			if(max_it!=it && (*max_it)==(*it)){
				two_max=true;
				break;
			}
		}
		if(two_max){
			auto min_it = min_element(nums.begin(), nums.end());
			(*min_it)+=2;
		}else{
			for(auto it=nums.begin(); it!=nums.end();++it){
				if(it!=max_it){
					++(*it);
				}
			}
		}
	}
	cout << count;
}

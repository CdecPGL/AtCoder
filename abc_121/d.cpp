// Score: 不正解/400

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>
#include <algorithm>
#include <memory>
#include <numeric>

using namespace std;

uint64_t hoge(uint64_t A, uint64_t i){
uint64_t hshuuki = 1 << i;
		uint64_t shuuki = hshuuki << 1;
		uint64_t shuukime = (A / shuuki + 1);
		uint64_t lshuuki_owari;
		if (i % 2)
		{
			lshuuki_owari = 0;
		}
		else
		{
			lshuuki_owari = shuukime % 2;
		}
		uint64_t nokori = A - shuukime * shuuki + 1;
		uint64_t r = 0;
		if (nokori <= hshuuki)
		{
			r = lshuuki_owari;
		}
		else
		{
			r = (lshuuki_owari + (nokori - hshuuki)) % 2;
		}
		return r;
}

int main()
{
	uint64_t A, B;
	cin >> A >> B;
	uint64_t res = 0;
	for (uint64_t i = 0; i < 64; ++i)
	{
		auto r = hoge(A, i) ^ hoge(B, i);		
		res |= r & 1;
		res <<= 1;
	}
	cout << res;
}
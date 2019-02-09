// Score: 200/200

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

constexpr int CITY_COUNT = 4;
constexpr int ROAD_COUNT = 3;

int main()
{
	array<int, CITY_COUNT> road_per_city;
	road_per_city.fill(0);
	for (int i = 0; i < ROAD_COUNT; ++i)
	{
		int a, b;
		cin >> a >> b;
		++road_per_city[a - 1];
		++road_per_city[b - 1];
	}
	cout << ((*max_element(road_per_city.begin(), road_per_city.end()) < CITY_COUNT - 1) ? "YES" : "NO");
}

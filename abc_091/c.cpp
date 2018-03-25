#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	size_t N;
	cin >> N;
	set<int> red_points;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		red_points.emplace(x * 1000 + y);
	}
	int nakayosi_count = 0;
	set<int> blue_points;
	for (int i = 0; i < N; ++i) {
		int bx, by;
		cin >> bx >> by;
		for (auto red_it = --red_points.end(); red_it != --red_points.begin(); --red_it) {
			int rx{ *red_it / 1000 }, ry{ *red_it % 1000 };
			if (rx < bx && ry < by) {
				red_points.erase(red_it);
				++nakayosi_count;
				break;
			}
		}
	}
	cout << nakayosi_count;
}

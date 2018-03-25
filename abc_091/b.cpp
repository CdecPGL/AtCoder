#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int N;
	cin >> N;
	unordered_map<string, int> point_map;
	for (int i = 0; i < N; ++i) {
		string word;
		cin >> word;
		if (point_map.find(word) != point_map.end()) {
			++point_map[word];
		}
		else {
			point_map.emplace(word, 1);
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string word;
		cin >> word;
		if (point_map.find(word) != point_map.end()) {
			--point_map[word];
		}
		else {
			point_map.emplace(word, -1);
		}
	}
	int max_point = 0;
	for (const auto& pair : point_map) {
		max_point = max(max_point, pair.second);
	}
	cout << max_point;
}

// Score: /400

#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

enum class Kind {Jinja, Tera, Start};

struct Point{
	Kind kind;
	uint64_t pos, left_t_dis, right_t_dis, left_s_dis, right_s_dis; 
};

int main()
{
	int A, B, Q;
	cin >> A >> B >> Q;
	vector<Point> points;
	points.reserve(A+B+Q);
	for (int a=0;a<A;++a){
		auto p = Point();
		p.kind = Kind::Jinja;
		cin >> p.pos;
		points.push_back(p);
	}
	for (int b=0;b<B;++b){
		auto p = Point();
		p.kind = Kind::Tera;
		cin >> p.pos;
		points.push_back(p);
	}
	for (int q=0;q<Q;++q){
		auto p = Point();
		p.kind = Kind::Start;
		cin >> p.pos;
		points.push_back(p);
	}
	sort(points.begin(), points.end(), [](Point l, Point r){return l.pos < r.pos;});
	uint64_t last_jinja_pos = -1000000000000;
	uint64_t last_tera_pos = -1000000000000;
	auto last_start_it = points.end();
	for(auto it = points.begin();it!=points.end();++it){
		switch(it->kind){
			case Kind::Tera:
				last_tera_pos = it->pos;
				if(last_start_it != points.end()){
					last_start_it->right_t_dis = it->pos - last_start_it->pos;
				}
				break;
			case Kind::Jinja:
				last_jinja_pos = it->pos;
				if(last_start_it != points.end()){
					last_start_it->right_s_dis = it->pos - last_start_it->pos;
				}
			break;
			case Kind::Start:
				last_start_it = it;
				it->left_s_dis = it->pos - last_jinja_pos;
				it->left_t_dis = it->pos - last_tera_pos;
			break;
		}
	}
	for(const auto& point : points){
		if(point.kind == Kind::Start){
			cout << min({
				max(point.left_s_dis, point.left_t_dis),
				max(point.right_s_dis, point.right_t_dis),
				point.right_s_dis*2+point.left_t_dis,
				point.right_t_dis*2+point.left_s_dis,
				point.left_s_dis*2+point.right_t_dis,
				point.left_t_dis*2+point.right_s_dis
			}) << endl;
		}
	}
}

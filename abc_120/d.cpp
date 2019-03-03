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

struct Group{
	int count = 2;
	uint64_t kumiawase = 1;
};

int main()
{
	int N, M;
	cin >> N >> M;
	unordered_map<int, unordered_set<int>> graph;
	vector<pair<int,int>> edge;
	for(int m=0;m<M;++m){
		int A, B;
		cin >> A >> B;
		edge.push_back({A, B});
	}

	vector<Group> group_list;
	vector<uint64_t> kimiawase_diff_list;
	unordered_map<int, std::shared_ptr<int>> isl_to_gidxp;
	for(auto it = edge.rbegin();it!=edge.rend();++it){
		decltype(auto) AB = *it;
		std::shared_ptr<int> Agidxp, Bgidxp;
		uint64_t diff = 0;
		if(isl_to_gidxp.find(AB.first)!=isl_to_gidxp.end()){
			Agidxp = isl_to_gidxp[AB.first];
		}
		if(isl_to_gidxp.find(AB.second)!=isl_to_gidxp.end()){
			Bgidxp = isl_to_gidxp[AB.second];
		}
		if(Agidxp==nullptr && Bgidxp==nullptr){
			auto ngidxp = std::make_shared<int>(group_list.size());
			Group ng;
			group_list.push_back(ng);
			diff = ng.kumiawase;
			isl_to_gidxp.emplace(AB.first, ngidxp);
			isl_to_gidxp.emplace(AB.second, ngidxp);
		}else if(Agidxp==nullptr && Bgidxp!=nullptr){
			isl_to_gidxp.emplace(AB.first, Bgidxp);
			diff =  group_list[*Bgidxp].count;
			group_list[*Bgidxp].kumiawase += diff;
			++group_list[*Bgidxp].count;
		}else if(Agidxp!=nullptr && Bgidxp==nullptr){
			isl_to_gidxp.emplace(AB.second, Agidxp);
			diff = group_list[*Agidxp].count;
			group_list[*Agidxp].kumiawase += diff;
			++group_list[*Agidxp].count;
		}else if(*Agidxp!=*Bgidxp) {
			diff = (uint64_t)group_list[*Agidxp].count * group_list[*Bgidxp].count;
			group_list[*Agidxp].kumiawase += diff;
			group_list[*Agidxp].count += group_list[*Bgidxp].count;
			for(auto&& gidxp_pair : isl_to_gidxp){
				if(*gidxp_pair.second==*Bgidxp){
					*gidxp_pair.second = *Agidxp;
				}
				// isl_to_gidxp[AB.second] = isl_to_gidxp[AB.first];
			}
			// isl_to_gidxp[AB.second] = isl_to_gidxp[AB.first];
		}
		kimiawase_diff_list.push_back(diff);
	}

	uint64_t acc_diff = 0;
	for(auto d : kimiawase_diff_list){
		acc_diff += d;
		cout << acc_diff << endl;
	}
}

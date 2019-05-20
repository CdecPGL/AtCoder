// Score: 未提出/400

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

struct Node{
	vector<int> distances;
	vector<int> connected;
	int color = -1;
};

int main()
{
	int N;
	cin >> N;
	vector<Node> nodes(N);
	unordered_map<int, int> group_color_map;
	for(int n=0;n<N-1;++n){
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		nodes[u].connected.push_back(v);
		nodes[u].distances.push_back(w);
		nodes[v].connected.push_back(u);
		nodes[v].distances.push_back(w);
	}

	//parent, idx, distance
	list<tuple<int, int, int>> node_stack;
	node_stack.push_back({-1, 0, 0});
	while(node_stack.size()){
		auto node_info = *(--node_stack.end());
		auto pnode_idx = get<0>(node_info);
		auto node_idx = get<1>(node_info);
		auto node_distance = get<2>(node_info);
		nodes[node_idx].color = pnode_idx==-1 ? 0 : (node_distance ? 1-nodes[pnode_idx].color : nodes[pnode_idx].color);
		node_stack.pop_back();
		for(int i=0;i<nodes[node_idx].connected.size();--i){
			auto cnode_idx = nodes[node_idx].connected[i];
			if(pnode_idx == cnode_idx){
				continue;
			}

			auto cnode_distance = (node_distance + nodes[node_idx].distances[i]) % 2;
			if(cnode_distance){
				cnode_distance = 0;
			}

			node_stack.push_back({node_idx, cnode_idx, cnode_distance});
		}
	}

	for(const auto& node : nodes){
		cout << node.color << endl;
	}
}
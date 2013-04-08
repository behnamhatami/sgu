#include <iostream> 
#include <vector>
using namespace std;

#define int_pair pair<int, int>

const int max_m = 1000 + 10;
const int max_n = 7;



int_pair edge[max_m];
bool mark[max_m] = {false};
vector<int_pair> graph[max_n];
int dfs_count[max_n] = {0};
vector<int_pair> order;
int e = 0;

void dfs(int v){
	while(dfs_count[v] < graph[v].size()){
		int count = dfs_count[v]++;
		int index = graph[v][count].second;
		int next = graph[v][count].first;
		if(mark[index])
			continue;
		else mark[index] = true;
		dfs(next);
		order.push_back(int_pair(index, (edge[index].first == v)?1:-1));
	}
}

int main(){
	cin >> e;
	for(int i = 0; i < e; i++){
		cin >> edge[i].first >> edge[i].second;
		graph[edge[i].first ].push_back(int_pair(edge[i].second, i));
		graph[edge[i].second].push_back(int_pair(edge[i].first , i));
	}

	{
		int count = 0;
		for(int i = 0; i < max_n; i++)
			if(graph[i].size()%2 == 1)
				count++;
			
		if(count > 2){
			cout << "No solution" << endl;
			return 0;
		}
		for(int i = 0; i < max_n; i++){
			if(graph[i].size() != 0 && (count == 0 || graph[i].size()%2 == 1)){
				dfs(i);
				break;
			}
		}
	}

	if(order.size() != e)
		cout << "No solution" << endl;
	else
		for(int i = order.size() - 1; i >= 0; i--)
			cout << (order[i].first+1) << " " << ((order[i].second>0)?"+":"-") << endl;

	return 0;
}
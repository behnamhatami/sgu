#include <iostream>
#include <vector>
using namespace std;

const int max_n = 200 + 5;

int n, e, color[max_n];
vector<int> edges[max_n];

bool dfs(int u, int col){
	color[u] = col;
	for(int i = 0; i < edges[u].size(); i++){
		int v = edges[u][i];
		if(color[v] != 0){
			if(color[v] != 3 - col)
				return false;
		}else{
			if(!dfs(v, 3 - col))
				return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> e;
	for(int i = 0; i < e; i++){
		int tp_a, tp_b;
		cin >> tp_a >> tp_b;
		tp_a--;
		tp_b--;
		edges[tp_a].push_back(tp_b);
		edges[tp_b].push_back(tp_a);
	}
	
	for(int i = 0; i < n; i++)
		if(color[i] == 0)
			if(!dfs(i, 1)){
				cout << "no" << endl;
				return 0;
			}

	cout << "yes" << endl;
	int count = 0;
	for(int i = 0; i < n; i++)
		if(color[i] == 1)
			count++;
	cout << count << endl;
	for(int i = 0; i < n; i++)
		if(color[i] == 1)
			cout << i + 1 << " ";
	cout << endl;
	return 0;
}
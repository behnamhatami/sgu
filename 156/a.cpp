#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define pr pair<int, int>

const int max_n = 10000;

int n, m, part[max_n];
bool mark[max_n];
vector<int> edges[max_n];
vector<int> ngh[max_n];

void dfs_init(int u, int part_no){
	part[u] = part_no;
	for(int j = 0; j < ngh[u].size(); j++)
		if(part[ngh[u][j]] == 0)
			dfs_init(ngh[u][j], part_no);
}

void dfs(int u){
	mark[u] = true;
	cout << u+1 << " ";
	for(int j = 0; j < ngh[u].size(); j++)
		if(!mark[ngh[u][j]])
			dfs(ngh[u][j]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	for(int u = 0; u < n; u++)
		if(edges[u].size() % 2 != 0){
			cout << "-1" << endl;
			return 0;
		}


	for(int u = 0; u < n; u++)
		if(edges[u].size() == 2)
			for(int j = 0; j < edges[u].size(); j++){
				const int v = edges[u][j];
				ngh[u].push_back(v);
				if(edges[v].size() != 2)
					ngh[v].push_back(u);
			}

	for(int u = 0, k = 0; u < n; u++)
		if(part[u] == 0)
			dfs_init(u, ++k);
	

	for(int u = 0; u < n; u++){
		if(ngh[u].size() != 2){
			vector<int> tmp;
			tmp.push_back(u);
			for(int j = 0; j < edges[u].size(); j++){
				int v = edges[u][j];
				if(edges[v].size() == 2)
					continue;
				tmp.push_back(v);
				int size = tmp.size();
				if(size >= 2){
					int u0 = tmp[size - 1];
					int v0 = tmp[size - 2];
					if(part[u0] != part[v0]){
						ngh[u0].push_back(v0);
						ngh[v0].push_back(u0);
						tmp.pop_back();
						tmp.pop_back();
					}
				}
			}
		}
	}


	dfs(0);
	cout << endl;
	return 0;
}

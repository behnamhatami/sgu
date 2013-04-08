#include <iostream>
#include <vector>
using namespace std;

#define pr pair<int, int>
#define mpr pair<pr, pr>
const int max_n = 10000;

int n, mark[max_n];
vector<mpr> edges[max_n];

int dfs(int u, int lev){
	mark[u] = lev;
	int max_val = 0;
	for(int j = 0; j < edges[u].size(); j++){
		const int v = edges[u][j].first.first;
		const int l = edges[u][j].first.second;
		const int m = edges[u][j].second.first;
		if(mark[v] == lev)
			continue;
		if(m == 0){
			edges[u][j].second.first = 1;
			edges[u][j].second.second = dfs(v, lev) + l;
		}
		max_val = max(max_val, edges[u][j].second.second);
	}
	return max_val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++){
		int v, l;
		cin >> v >> l;
		v--;
		edges[i].push_back(mpr(pr(v, l), pr(0, 0)));
		edges[v].push_back(mpr(pr(i, l), pr(0, 0)));
	}

	fill(mark, mark + n, -1);

	for(int i = 0; i < n; i++)
		dfs(i, i);

	for(int i = 0; i < n; i++){
		int mx = 0;
		for(int j = 0; j < edges[i].size(); j++)
			if(mx < edges[i][j].second.second)
				mx  = edges[i][j].second.second;
		cout << mx << endl;
	}

	return 0;
}
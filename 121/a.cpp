#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pr pair<int, int>
const int max_n = 100;

int n, deg[max_n];
pr bts[max_n];
vector<int> edge[max_n];
bool m[max_n][max_n];;


void bt(const int lev){
	if(lev == n){
		for(int u = 0; u < n; u++){
			for(unsigned int j = 0; j < edge[u].size(); j++)
				if(m[u][edge[u][j]])
					cout << "2" << " ";
				else cout << "1" << " ";
			cout << "0" << endl;
		}
		exit(0);
	}

	int u = bts[lev].second;

	if(edge[u].size() != deg[u]){
		bt(lev + 1);
		return;
	}

	if(deg[u] <= 1 && edge[u].size() > 1)
		return;

	if(edge[u].size() <= 1)
		bt(lev + 1);

	for(unsigned int i = 0; i < edge[u].size(); i++){
		const int v = edge[u][i];
		if(deg[v] > 1){
			m[u][v] = true;
			m[v][u] = true;
			deg[v] --;
			deg[u] --;
			bt(lev + 1); 
			deg[u] ++;
			deg[v] ++;
			m[v][u] = false;
			m[u][v] = false;
		}
	}
}

int main(){
	cin >> n;
	for(int u = 0; u < n; u++){
		int v;
		while(true){
			cin >> v;
			if(v == 0)
				break;
			edge[u].push_back(v-1);
		}
		deg[u] = edge[u].size();
		bts[u].second = u;
		bts[u].first = deg[u];
	}
	sort(bts, bts+n);
	bt(0);
	cout << "No solution" << endl;
	return 0;
}
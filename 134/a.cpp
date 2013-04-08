#include <iostream>
#include <vector>
using namespace std;

const int max_n = 16000;

int n, tpu, tpv;
int ans[max_n] , child[max_n];
vector<int> edge[max_n];
bool mark[max_n];

void dfs(int u){
	mark[u] = true;
	int tpch = 0, tpans = 0;
	for(unsigned int i = 0; i < edge[u].size(); i++){
		if(mark[edge[u][i]])
			continue;
		else dfs(edge[u][i]);
		tpch += child[edge[u][i]];
		tpans = max(tpans, child[edge[u][i]]);
	}
	child[u] = tpch + 1; 
	ans[u] = max(n - child[u], tpans);
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> tpu >> tpv;
		tpu--; tpv--;
		edge[tpu].push_back(tpv);
		edge[tpv].push_back(tpu);
	}

	dfs(0);
	int tpans = max_n;
	int count_ans = 0;

	for(int i = 0; i < n; i++){
		if(ans[i] == tpans)
			count_ans++;
		
		if(ans[i] < tpans){
			tpans = ans[i];
			count_ans = 1;
		}
	}

	cout << tpans << " " << count_ans << endl;
	for(int i = 0; i < n; i++)
		if(ans[i] == tpans)
			cout << i + 1 << " ";
	cout << endl; 
	return 0;
}
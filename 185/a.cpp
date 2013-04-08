	#include <iostream>
	#include <vector>
	#include <set>

	using namespace std;

	#define sh(s) cerr << #s << " --> " << s << endl
	#define pt pair<int, int>

	const int max_n = 400 + 2;
	const int inf = 10000 * max_n;

	int n, e;
	int value[max_n];
	vector<pt>* graph;
	bool mark[max_n];
	bool mk[max_n][max_n], dg[max_n][max_n];

	class heap{
	public:
		int *hp, *ind;
		int size;

		heap(int n){
			size = n + 1;
			hp = new int[size];
			ind = new int[n];
			for(int i = 1; i < size; i++){
				ind[i - 1] = i;
				hp[i] = i - 1;
			}
		}

		void set(int &a, int val_a, int &b, int val_b){
			a = val_a;
			b = val_b;
		}

		void swap(int i, int j){
			set(hp[i], hp[j], hp[j], hp[i]);
			set(ind[hp[i]], i, ind[hp[j]], j);
		}

		void heap_down(int mhs){
			int lhs = 2 * mhs;
			int rhs = 2 * mhs + 1;
			if(lhs >= size)
				return;
			
			if(rhs >= size){
				if(value[hp[lhs]] < value[hp[mhs]]){
					swap(lhs, mhs);
					heap_down(lhs);
				}
				return;
			}

			int chs = value[hp[lhs]] < value[hp[rhs]] ? lhs : rhs;
			if(value[hp[chs]] < value[hp[mhs]]){
				swap(chs, mhs);
				heap_down(chs);
			}
		}

		void heap_up(int mhs){
			if(mhs == 1)
				return;
			int fhs = mhs / 2;
			if(value[hp[mhs]] < value[hp[fhs]]){
				swap(fhs, mhs);
				heap_up(fhs);
			}
		}

		int remove_min(){
			swap(1, --size);
			heap_down(1);
			return hp[size];
		}

		void print(){
			for(int i = 1; i < size; i++)
				cout << "(" << hp[i] << " " << ind[hp[i]] << ") "; 
			cout << endl;
		}
	};

	bool dfs(int v){
		mark[v] = true;
		if(v == n - 1)
			return true;
		for(int i = 0; i < n; i++)
			if(dg[v][i] && !mark[i])
				if(dfs(i)){
					mk[v][i] = true;
					dg[i][v] = true;
					dg[v][i] = false;
					return true;
				}

		return false;
	}

	void dfs_r(int v){
		mark[v] = true;
		cout << v + 1 << " ";
		if(v == n - 1)
			return;
		for(int i = 0; i < n; i++){
			if(!mark[i] && mk[v][i] && !mk[i][v]){
				mk[v][i] = false;
				dfs_r(i);
				return;
			}
		}
	}

	int main(){
		ios_base::sync_with_stdio(false);
		cin >> n >> e;
		heap hp(n);

		graph = new vector<pt >[n];

		for(int i = 0; i < e; i++){
			int u, v, l;
			cin >> u >> v >> l;
			u--; v--;
			graph[u].push_back(pt(v, l));
			graph[v].push_back(pt(u, l));
		}
		 
		fill(value, value + n, inf);
		value[0] = 0;

		for(int k = 0; k < n; k++){
			int src = hp.remove_min();

			if(value[src] == inf || src == n - 1)
				break;

			for(unsigned int j = 0; j < graph[src].size(); j++){
				int des = graph[src][j].first;
				int len = graph[src][j].second;
				if(value[des] > len  + value[src]){
					value[des] = len  + value[src];
					hp.heap_up(hp.ind[des]);
				}
			}
		}

		for(int i = 0; i < n; i++)
			for(unsigned int j = 0; j < graph[i].size(); j++){
				int des = graph[i][j].first;
				int len = graph[i][j].second;
				if(value[i] + len > value[des])
					dg[i][des] = false;
				else dg[i][des] = true;
			}

		fill(mark, mark + n, false);
		if(!dfs(0)){
			cout << "No solution" << endl;
			return 0;
		}

		fill(mark, mark + n, false);
		if(!dfs(0)){
			cout << "No solution" << endl;
			return 0;
		}

		fill(mark, mark + n, false);
		dfs_r(0);
		cout << endl;

		fill(mark, mark + n, false);
		dfs_r(0);
		cout << endl;

		return 0;
	}
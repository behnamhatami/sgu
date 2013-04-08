#include <iostream>
using namespace std;

const int max_n = 10000;

int n, e;
int deg[max_n];
long long sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> e;
	int tp_u, tp_v;
	for (int i = 0; i < e; i++)
	{
		cin >> tp_u >> tp_v;
		deg[tp_u-1]++;
		deg[tp_v-1]++;
	}

	for (int i = 0; i < n; i++)
		sum += deg[i] * deg[i];

	cout << sum << endl;
	return 0;
}
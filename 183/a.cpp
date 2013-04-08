#include <iostream>
#include <cmath>
using namespace std;

#define sh(s) cerr << #s << " --> " << s << endl

const int max_n = 10000;
const int max_m = 100;

int n, m;
int val[max_n];
int d[max_m];
int hp[max_m][max_m];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> val[i];

	for(int i = 0; i < m - 1; i++){
		for(int j = 0; j <= i; j++)
			d[j] = val[i - j];

		for(int k = 0; k <= i; k++)
			if(k == 0)
				hp[i][k] = d[k];
			else hp[i][k] = min(d[k], hp[i][k - 1]);
	}

	for(int i = m - 1; i < n; i++){
		for(int j = 0; j < m - 1; j++)
			d[j] = hp[(i - j - 1)%(m-1)][m - 2  - j] + val[i - j];
		
		for(int k = 0; k < m - 1; k++)
			if(k == 0)
				hp[i%(m-1)][k] = d[k];
			else hp[i%(m-1)][k] = min(d[k], hp[i%(m-1)][k - 1]);
	}

	cout << hp[(n - 1)%(m-1)][m - 2] << endl;
	return 0;
}
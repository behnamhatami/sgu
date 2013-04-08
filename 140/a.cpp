#include <iostream>
#include <vector>
using namespace std;

const int max_n = 100;
const int max_m = 100 * 100;
const string no = "NO";
const string yes = "YES";

struct father
{
	int me, fa, ct;
};

int n, mod, base;
int in[max_n];
int ans[max_n];
bool dyn[max_m];
father dyn_father[max_m];

int new_key(int k, int i){
	return (k + in[i]) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> mod >> base;
	dyn[0] = true;
	dyn_father[0].me = -1;
	dyn_father[0].fa = -1;
	dyn_father[0].ct = 0;

	for(int i = 0; i < n; i++){
		cin >> in[i];
		in[i] %= mod;

		for(int j = 0; j < mod; j++)
			if(dyn[j]){
				int count = 1;
				int k = new_key(j, i);
				while(!dyn[k]){
					dyn[k] = true;
					dyn_father[k].me = i;
					dyn_father[k].fa = j;
					dyn_father[k].ct = count;

					k = new_key(k, i);
					count++;
				}
			}
	}

	if (dyn[base]){
		cout << yes << endl;
		while(dyn_father[base].me != -1){
			ans[dyn_father[base].me] += dyn_father[base].ct; 
			base = dyn_father[base].fa;
		}
		for(int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}else{
		cout << no << endl;
	}
	return 0;
}



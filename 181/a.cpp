#include <iostream>
#include <cstdlib>

using namespace std;

const int max_m = 1000;

int a, alpha, beta, gamma, m, k;
int mark[max_m];

void answer(int ans){
	cout << ans << endl;
	exit(0);
}

void clear(){
	for(int i = 0; i < m; i++)
		mark[i] = -1;
}

void loop(){
	clear();
	int lp, x = a % m;
	for(int i = 0;; i++){
		if(i == k)
			answer(x);
		
		if(mark[x] != -1){
			lp = i - mark[x];
			break;
		}else mark[x] = i;

		x = (alpha * x * x + beta * x + gamma) % m;
	}

	a = x;
	k -= lp + mark[x];
	k %= lp;
	loop();
}

int main(){
	cin >> a >> alpha >> beta >> gamma >> m >> k;

	if(k == 0)
		answer(a);
	loop();
}
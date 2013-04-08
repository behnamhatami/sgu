#include <iostream>
#include <algorithm>
using namespace std;

#define pr pair<int, int>

const int max_n = 20000;


int n, pl;
pr in[max_n];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	long long sp = 0; 
	for(int i = 0; i < n; i++){
		cin >> in[i].first >> in[i].second;
		sp += in[i].second;
	}
	sort(in, in + n);
	
	for(long long i = 0, j = 0; i < n; i++){
		j += in[i].second;
		if(j >= sp - j){
			cout << in[i].first << ".00000" << endl;
			break;
		}
	}
	return 0;
}
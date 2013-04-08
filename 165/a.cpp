#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int max_n = 6000;
const int max_d = 1e5;
const int mid = 2e6;

#define pr pair<int, int>

int n, ans[max_n];
pr in[max_n];

int main(){
	cin >> n;
	long double t;
	for(int i = 0; i < n; i++){
		cin >> t;
		in[i].first = ceil(t * 1e6) - mid;
		in[i].second = i;
	}

	sort(in, in + n);
	for(int i = 0, j = n - 1, k = 0, sum = 0; k < n; k++){
		if(sum >= 0){
			sum += in[i].first;
			ans[k] = in[i].second;
			i++;
		}else{
			sum += in[j].first;
			ans[k] = in[j].second;
			j--;
		}
	}
	cout << "yes" << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
	return 0;
}
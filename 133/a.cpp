#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define pt pair<unsigned int,unsigned int>
const int max_n = 16000;

int n, ans;
unsigned int mx;
pt in[max_n];


int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> in[i].first >> in[i].second;
	sort(in, in + n);
	mx = in[0].second;

	for(int i = 1; i < n; i++)
		if(mx > in[i].second)
			ans++;
		else mx = in[i].second;
	cout << ans << endl;
	return 0;
}
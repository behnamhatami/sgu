#include <iostream>
using namespace std;

int k;
int ans = 0;

int main(){
	cin >> k;
	// 1
	ans++;
	// 2
	if((k-1)%3 == 0)
		ans++;
	// 3
	if(k == 1)
		ans++;
	// 4
	if(k == 1)
		ans++;
	// 5
	if((k-1)%3 == 0)
		ans++;
	// 6
	if((k-1)%3 == 0){
		int start = 0;
		for(int i = 1; i < k; i++)
			start = (start * 10 + 1) % 7;
		if(start == 0)
			ans++;
	}
	// 7
	if(k == 1)
		ans++;
	// 8
	if(k == 1)
		ans++;
	cout << ans << endl;
	return 0;
}
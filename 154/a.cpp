#include <iostream>
#include <cstdlib>
using namespace std;

int n = 0, mn = 0, mx = 1e8 + 1;

int num_of_zero(int num){
	int ans = 0;
	while(num > 0){
		ans += num / 5;
		num /= 5;
	}
	return ans;
}

void answer(int ans){
	cout << ans << endl;
	exit(0);
}

int main(){
	cin >> n;
	if(n == 0)
		answer(1);
	while(mn < mx){
		int mid = (mx + mn)/2;
		// cout << mn << " " << mid << " " << mx << endl;
		int ans = num_of_zero(mid * 5);
		if(ans == n)
			answer(mid * 5);

		if(ans < n)
			mn = mid + 1;

		if (ans > n)
			mx = mid;
	}
	cout << "No solution" << endl;
	return 0;
}
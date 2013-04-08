#include <iostream>
using namespace std;

#define ll long long

ll n;

int solve(ll rm, ll k){
	if(rm <= k + 1)
		return 0;
	return solve((rm - k) / 2 - 1, k + 1) + 1;
}

int main(){
	cin >> n;
	cout << solve(n, 0) << endl;
	return 0;
}
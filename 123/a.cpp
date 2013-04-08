#include <iostream>
using namespace std;


#define ll long long

int k;
ll a, b, sum;

void set(ll &a, ll val_a, ll &b, ll val_b){
	a = val_a;
	b = val_b;
}

int main(){
	cin >> k;
	a = 0, b = 1, sum = 1;
	for (int i = 1; i < k; i++){
		set (a, b, b, a + b);
		sum += b;
	}

	cout << sum << endl;
	return 0;
}
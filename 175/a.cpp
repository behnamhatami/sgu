#include <iostream>
using namespace std;

int n, q;

int compute(int n, int q){
	if(n == 1)
		return 0;

	int mid = n/2;
	if(q >= mid)
		return compute(n - mid, n - 1 - q);
	else return n - mid + compute(mid, mid - 1 - q);
}

int main(){
	cin >> n >> q;
	cout << compute(n, q - 1) + 1 << endl;
	return 0;
}
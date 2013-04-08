#include <iostream>
using namespace std;

#define ll long long

const ll max_n = 1000000000;

int n;

int main(){
	// for(long long i = 0; i < max_n; i++)
		// if((i * i) % max_n == 987654321)
			// cout << i << endl;
	ios_base::sync_with_stdio(false);
	cin >> n;
	if(n < 9)
		cout << 0 << endl;
	
	if(n == 9)
		cout << 8 << endl;

	if (n > 9){
		cout << 72;
		for(int i = 10; i < n; i++)
			cout << 0;
		cout << endl;
	}
	return 0;
}
#include <iostream> 
using namespace std;

int n;

int gcd(int a, int b){
	int c;
	while(a != 0 && b != 0){
		c = a;
		a = b % c;
		b = c;
	}
	return b;
}

int main(){
	cin >> n;
	int count = 0;
	for(int i = 1; i <= n; i++)
		if(gcd(i, n) == 1)
			count++;

	cout << count << endl;
	return 0;
}
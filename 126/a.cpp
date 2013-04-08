#include <iostream>
#include <cmath>
using namespace std;

int a, b;

void set(int &a, int val_a, int &b, int val_b){
	a = val_a;
	b = val_b;
}

int main(){
	cin >> a >> b;
	int sum = a + b;
	int count = 0;

	while(a != 0 && b != 0){
		if(sum % 2 != 0 && sum > 1){
			cout << -1 << endl;
			return 0;
		}else sum /= 2;

		set(a, min(a, b) * 2, b, max(a, b) - min(a, b));
		count ++;
	}

	cout << count << endl;
	return 0;
}
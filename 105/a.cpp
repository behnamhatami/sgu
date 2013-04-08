#include <iostream>
using namespace std;

int n;

int main(){
	cin >> n;
	switch(n % 3){
		case 0:
			cout << (n / 3) * 2 << endl;
			return 0;
		case 1:
			cout << (n / 3) * 2 << endl;
			return 0;
		case 2:
			cout << (n / 3) * 2 + 1 << endl;
			return 0;
	}
}
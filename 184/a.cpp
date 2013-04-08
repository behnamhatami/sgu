#include <iostream>
#include <cmath>
using namespace std;

int p, m, c, k, r, v;

int main(){
	cin >> p >> m >> c >> k >> r >> v;
	cout << min(min(p / k, m / r), c / v) << endl;
	return 0;
}
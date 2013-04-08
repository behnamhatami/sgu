#include <iostream>
#include <iomanip>
using namespace std;

int x, y;
long double z;
long double ans;

int main(){
	cin >> x >> y >> z;
	x = x * 60;
	y = y * 60;
	ans = 1 - ((y - x - z) * (y - x - z)) / ((y - x) * (y - x));
	cout << fixed;
	cout << setprecision(7) << ans << endl;
	return 0;
}

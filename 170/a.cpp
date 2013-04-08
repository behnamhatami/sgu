#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string a, b;

int main(){
	cin >> a >> b;
	{
		if(a.length() != b.length()){
		cout << -1 << endl;
		return 0;
		}
	}
	int ans = 0, n = a.length();
	int i, j;
	for(i = 0, j = 0; true; i++, j++){
		for(;i<n && a[i] != '-'; i++);
		for(;j<n && b[j] != '-'; j++);
		if(i == n || j == n)
			break;
		ans += abs(i - j);
	}
	if(i != j)
		cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
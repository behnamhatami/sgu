#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 10000;

int n, k, p;
int in[max_n];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> k >> n;
	for(int i = 0; i < n; i++)
		cin >> in[i];
	sort(in, in + n);
	for(int i = 0, j = 0; i < n; i++, j++){
		bool newpage = false;
		if (i == 0)
			newpage = true;
		else if(in[i]/1000 != in[i-1]/1000 || j ==k){
			newpage = true;
			j = 0;
		}

		if(newpage)
			p++;
	}

	cout << p + 2 << endl;
	return 0;
}
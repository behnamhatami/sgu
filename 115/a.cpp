#include <iostream>
using namespace std;

int n, m;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 


int main(){
	cin >> n >> m;
	m--;
	n--;
	if (m > 11 || m < 0 || n < 0 || n >= month[m]){
		cout << "Impossible" << endl;
		return 0;
	}

	int count = 0;
	for(int i = 0; i < m; i++)
		count += month[i];
	count += n;
	count %= 7;

	cout << count  + 1 << endl;
	return 0;
}

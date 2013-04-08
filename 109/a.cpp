#include <iostream>
using namespace std;

int n;

int min_odd;

void print_line(int ln){
	int i = 0, j = 0;
	for(;i < n && i + j != ln; i++);
	if (i == n)
		i--;
	for(;j < n && i + j != ln; j++);
	while(i >= 0 && j < n){
		cout << i*n + j + 1 << " ";
		i--;
		j++;
	}
}

int main(){
	cin >> n;
	if(n % 2 == 0)
		min_odd = n + 1;
	else
		min_odd = n;
	
	if(n == 1)
		return 0;

	if(n > 2){
		cout << n << " ";
		for(int i = n + 1; i < (2 * n - 1); i++)
			print_line(i);
		cout << endl;

		if(n == min_odd)
			min_odd += 2;
	}
	
	for(int i = n; i > 0; i--, min_odd += 2){
		cout << min_odd <<  " ";
		print_line(i);
		cout << endl;
	}

	return 0;
}
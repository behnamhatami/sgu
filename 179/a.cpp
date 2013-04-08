#include <iostream>
using namespace std;

#define ll long long

const int max_len = 10000;

string s;
int n;

int main(){
	cin >> s;
	n = s.size();

	int count = 0, i;
	for(i = n - 1; i >= 0; i--){
		if(s[i] == ')')
			count++;
		else{
			count--;
			if(count > 0)
				break;
		}
	}
	if(i == -1){
		cout << "No solution" << endl;
		return 0;
	}

	s[i] = ')';
	s[i+1] = '(';
	count = 0;
	for(int j = i + 1; j < n; j++)
		if(s[j] == '(')
			count++;
	for(int j = i + 1; j <= i + count; j++)
		s[j] = '(';
	for(int j = i + count + 1; j < n; j++)
		s[j] = ')';
	cout << s << endl;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int mx = 4 * 10000;

vector<int> prime;
int n;

bool is_prime(int in, int &dev){
	for(unsigned int i = 0; i < prime.size() && prime[i]*prime[i] <= in; i++)
		if(in % prime[i] == 0){
			dev = prime[i];
			return false;
		}
	return true;
}

int main(){
	int temp, help;
	for(int i = 2; i < mx; i++)
		if(is_prime(i, temp))
			prime.push_back(i);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		bool ans = true;
		if(is_prime(temp, help))
			ans = false;
		else if(!is_prime(temp/help, help))
				ans = false;
		if(ans)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
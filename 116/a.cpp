#include <iostream>
#include <vector>
using namespace std;

const int max_n = 10000 + 10;
const int inf = max_n;

int n;
vector<int> prime;
vector<int> super;
int sup[max_n][2];

bool is_prime(int num){
	for(unsigned int i = 0; i < prime.size() && prime[i]*prime[i] <= num; i++)
		if(num % prime[i] == 0)
			return false;
	return true;
}

int main(){
	cin >> n;
	for(int i = 2; i <= n; i++)
		if(is_prime(i))
			prime.push_back(i);

	for(int i = 0; i <= n; i++){
		sup[i][0] = inf;
		sup[i][1] = i;
	}

	for(unsigned int i = 1; i < prime.size(); i++)
		if(is_prime(i+1)){
			sup[prime[i]][0] = 1;
			super.push_back(prime[i]);
		}

	for(int i = 1; i <= n; i++){
		for(unsigned int j = 0; j < super.size() && super[j] < i ; j++){
			int first = super[j];
			int second = i - first;
			if(sup[i][0] >= sup[second][0] + 1){
				sup[i][0] = sup[second][0] + 1;
				sup[i][1] = first;
			}
		}
	}

	if(sup[n][0] == inf){
		cout << 0 << endl;
		return 0;
	}else{
		cout << sup[n][0] << endl;
		int i = n;
		while(i != 0){
			cout << sup[i][1] << " ";
			i -= sup[i][1];
		}
		cout << endl;
		return 0;
	}
}
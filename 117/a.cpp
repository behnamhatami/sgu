#include <iostream>
#include <vector>
using namespace std;

#define pt pair<int, int> 

const int max_n = 10000 + 1;

int n, m, k, ans;
vector<int> prime;

bool is_prime(int num){
	for(unsigned int i = 0; i < prime.size() && prime[i] * prime[i] <= num; i++)
		if(num % prime[i] == 0)
			return false;
	return true;
}

vector<pt> factor(int num){
	vector<pt> ans;
	for(unsigned int i = 0; i < prime.size() && prime[i] <= num; i++){
		int count = 0;
		
		while(num % prime[i] == 0){
			count++;
			num /= prime[i];
		}

		if(count > 0)
			ans.push_back(pt(prime[i], count));
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 2; i < max_n; i++)
		if(is_prime(i))
			prime.push_back(i);

	int tp;
	vector<pt> k_fact = factor(k);
	for(int i = 0; i < n; i++){
		cin >> tp;
		bool res = true;
		for(unsigned int j = 0; res && j < k_fact.size(); j++){
			int count = 0;
			while(tp % k_fact[j].first == 0){
				tp /= k_fact[j].first;
				count++;
			}

			if(count * m < k_fact[j].second)
				res = false;
		}
		if(res)
			ans++;
	}

	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

#define pt pair<int, int>

const int max_k = 5000 + 2;
const int mod = 128;

int n, k, ct;
pt val[max_k];
bool array[mod];

int main(){
	ios_base::sync_with_stdio(false);
	fill(array, array + mod, false);

	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> val[i].first;
		val[i].second = i;
	}

	sort(val, val+k);

	for(int i = 1, j = 0, sum = 1; i <= n; i++, sum++){
		
		{
			int ind = i % mod;
			if(!array[ind]){
				ct++;
				while(j < k && ct == val[j].first){
					val[j].first  = val[j].second;
					val[j].second = i;
					j++;
				}
			}else array[ind] = false;
		}
		{
			int l = i;
			while(l % 10 == 0 && l != 0){
				sum -= 9;
				l /= 10;
			}
		}
		array[(i + sum) % mod] = true;
	}

	sort(val, val+k);

	cout << ct << endl;
	for(int i = 0; i < k; i++)
		cout << val[i].second << " ";
	if(k != 0)
		cout << endl;
	return 0;
}
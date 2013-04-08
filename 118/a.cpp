#include <iostream>
using namespace std;

const int max_n = 1000 + 1;

int k, n, tp;
int input[max_n];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> k;
	for(int l = 0; l < k; l++){
		cin >> n;
		
		for(int i = 0; i < n; i++)
			cin >> input[i];

		if(input[0] == 0){
			cout << 0 << endl;
			continue;
		}else{
			int ans = 0;
			for(int i = n - 1; i >= 0; i--)
				ans = ((ans + 1) * (input[i] % 9)) % 9;
			if(ans == 0)
				ans = 9;
			cout << ans << endl;
		}
	}
	return 0;
}
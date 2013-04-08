#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int max_l = 10; 
const int ten = 10;

int k;

bool get_mask(const int mask, const int bt){
	return (mask >> bt) % 2;
}

void set_mask(int &mask, const int bt){
	mask += 1 << bt;
}

void solve(){
	vector<int> ans;
	set<int> st;
	int n, m, in[max_l];

	in[0] = 1;
	cin >> n >> m;
	m++;

	for(int i = 1; i < m; i++)
		cin >> in[i]; 

	int mask = 1;
	for(int i = 1; i < ten; i++)
		for(int j = 0; j < m; j++)
			if(in[j] < i && !get_mask(mask, i - in[j])){
				set_mask(mask, i);
				break;
			}
	
	st.insert(mask);
	ans.push_back(mask);
	while(true){
		for(int i = 0; i < ten; i++){
			mask = mask / 2;
			for(int j = 0; j < m; j++)
				if(!get_mask(mask, 9 - in[j])){
					set_mask(mask, 9);
					break;
				}
		}
		if(st.count(mask) > 0)
			break;
		st.insert(mask);
		ans.push_back(mask);
	}

	int pl = 0;
	for(; ans[pl] != mask; pl++){
		if(pl == 10)
			return;
	}

	int rem = n % 10;
	n = n / 10;

	if(n >= ans.size()){
		n -= pl;
		n = n % (ans.size() - pl);
		n += pl;
	}

	n = n * 10 + rem;

	if(get_mask(ans[n/10], n % 10))
		cout << "FIRST PLAYER MUST WIN" << endl;
	else cout << "SECOND PLAYER MUST WIN" << endl;
}


int main(){
	cin >> k;

	for(int i = 0; i < k; i++)
		solve();
	return 0;
}
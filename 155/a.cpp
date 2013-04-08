#include <iostream>
#include <algorithm>
using namespace std;

#define pb pair<int, int>
#define pr pair<pb, int>

const int max_n = 50000;
const int inf = 100000;

int n;
pr in[max_n];
pr ans[max_n];


class segment{
	// 0 white
	// 1 black
	int* arr;
	int r_size;
public:
	segment(){
		r_size = 1;
		while(r_size < n)
			r_size *= 2;
		arr = new int[2 * r_size];
		for(int i = r_size; i < 2 * r_size; i++)
			arr[i] = i - r_size;

		for(int i = r_size - 1; i > 0; i--)
			arr[i] = get(arr[2*i]) < get(arr[2 * i + 1]) ? arr[2*i] : arr[2 * i + 1];

		// for(int i = 0; i < n; i++)
		// 	cout << in[i].second << " " << in[i].first.first
		// 	<< " " << in[i].first.second << endl;

		// for(int i = 1; i < 2 * r_size; i++){
		// 	int j = i;
		// 	while(j % 2 == 0){
		// 		cout << "|";
		// 		j /= 2;
		// 	}
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;
	}

	int get_min(int mn, int mx){
		return get_min(1, mn + r_size, mx + r_size, r_size, 2 * r_size);
	}

private:
	int get_min(int ind, int mn, int mx, int rmn, int rmx){
		if(mn == rmn && mx == rmx)
			return arr[ind];
		int mid = (rmn + rmx) / 2;
		if (mn >= mid)
			return get_min(2 * ind + 1, mn, mx, mid, rmx);
		else if(mx <= mid)
			return get_min(2 * ind + 0, mn, mx, rmn, mid);
		else{
			int ans1 = get_min(2 * ind + 0, mn, mid, rmn, mid);
			int ans2 = get_min(2 * ind + 1, mid, mx, mid, rmx);
			return (get(ans1) < get(ans2)) ? ans1 : ans2;
		}
	}

	int get(int index){
		if (index < n)
			return in[index].first.second;
		else return inf;
	}
};

segment* sg;

int make_tree(int first, int second, int parent){
	if(first == second)
		return -1;
	int mn = sg->get_min(first, second);
	int	ind = in[mn].second;
	ans[ind].second = parent;
	ans[ind].first.first = make_tree(first, mn, ind);
	ans[ind].first.second = make_tree(mn + 1, second, ind);
	return ind;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		in[i].second = i;
		cin >> in[i].first.first >> in[i].first.second;
	}
	sort(in, in + n);
	sg = new segment();
	make_tree(0, n, -1);
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i].second + 1 << " " 
			 << ans[i].first.first + 1 << " "
			 << ans[i].first.second  + 1 << endl;
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

#define pb pair<int, bool>
#define sh(s) cerr << #s << " --> " << s << endl;

class segment{
	// 0 white
	// 1 black
	pb* arr;
	int r_size;
public:
	segment(int n){
		r_size = 1;
		while(r_size < n)
			r_size *= 2;
		arr = new pb[2 * r_size + 1];
		for(int i = 1; i <= 2 * r_size; i++){
			arr[i].first = -1; // time
			arr[i].second = false; // color
		}
	}

	void paint(int mn, int mx, int tm, bool color){
		paint(1, mn, mx, 0, r_size, tm, color);
	}

	pb get(int ind){
		int index = ind + r_size;
		pb ans = arr[index];
		while(index >= 1){
			if(arr[index].first > ans.first){
				ans.first  = arr[index].first ;
				ans.second = arr[index].second;
			}
			index /= 2;
		}
		return ans;
	}

	void print(){
		for(int i = 0; i < r_size; i++)
			cerr << (get(i).second?1:0) << " ";
		cerr << endl;
	}

private:
	void paint(int index, int mn, int mx, int rmn, int rmx, int tm, bool color){
		if(mn == rmn && mx == rmx){
			if(tm > arr[index].first){
				arr[index].first = tm;
				arr[index].second = color;
			}
			return;
		}
		int mid = (rmn + rmx) / 2;
		if(mx <= mid)
			paint(2 * index    , mn, mx, rmn, mid, tm, color);
		else if(mn >= mid)
			paint(2 * index + 1, mn, mx, mid, rmx, tm, color);
		else{
			paint(2 * index    , mn , mid, rmn, mid, tm, color);
			paint(2 * index + 1, mid, mx , mid, rmx, tm, color);
		}
	}
};

class segment_2d{
	// 0 white
	// 1 black
	segment** arr;
	int r_size;
public:
	segment_2d(int n){
		r_size = 1;
		while(r_size < n)
			r_size *= 2;
		arr = new segment*[2 * r_size + 1];
		for(int i = 1; i <= 2 * r_size; i++)
			arr[i] = new segment(n);
	}

	void paint(int mn, int mx, int mn_2, int mx_2, int tm, bool color){
		paint(1, mn, mx, mn_2, mx_2, 0, r_size, tm, color);
	}

	pb get(int ind, int ind_2){
		int index = ind + r_size;
		pb ans = arr[index]->get(ind_2);
		while(index >= 1){
			pb tmp = arr[index]->get(ind_2);
			if(tmp.first > ans.first)
				ans = tmp;
			index /= 2;
		}
		return ans;
	}

	void print(){
		for(int i = 0; i < r_size; i++){
			for(int j = 0; j < r_size; j++)
				cerr << get(i, j).second << " ";
			cerr << endl;
		}
		cerr << endl;
	}

private:
	void paint(int index, int mn, int mx, int mn_2, int mx_2, int rmn, int rmx, int tm, bool color){
		if(mn == rmn && mx == rmx){
			arr[index]->paint(mn_2, mx_2, tm, color);
			return;
		}
		int mid = (rmn + rmx) / 2;
		if(mx <= mid)
			paint(2 * index    , mn, mx, mn_2, mx_2, rmn, mid, tm, color);
		else if(mn >= mid)
			paint(2 * index + 1, mn, mx, mn_2, mx_2, mid, rmx, tm, color);
		else{
			paint(2 * index    , mn , mid, mn_2, mx_2, rmn, mid, tm, color);
			paint(2 * index + 1, mid, mx , mn_2, mx_2, mid, rmx, tm, color);
		}
	}
};

int n, m;

int main(){
	cin >> n >> m;
	segment_2d square(n);

	int a, b, c, d;
	char color;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c >> d >> color;
		a--; b--; c--; d--;
		square.paint(min(a, c), max(a, c) + 1, min(b, d), max(b, d) + 1, i, (color == 'b'));
	}

	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			count += square.get(i, j).second;
	cout << n * n - count << endl;
	return 0;
}
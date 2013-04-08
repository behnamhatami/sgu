#include <iostream>
using namespace std;


#define ll long long
const int max_n = 66000;


int n;
int in[max_n], temp[max_n];

ll quick_sort(int start, int end, int arr[], int tmp[]){
	if(end - start <= 1)
		return 0;
	ll ans = 0;
	int mid = (end + start)/2;
	ans += quick_sort(start, mid, arr, tmp);
	ans += quick_sort(mid, end, arr, tmp);
	for(int i = start, j = mid, pt = start; pt < end; pt++){
		if(j == end || ((i < mid) && (in[i] <= in[j])))
			tmp[pt] = in[i++];
		else{
			tmp[pt] = in[j++];
			ans += (mid - i);
		}
	}
	for(int i = start; i < end; i++)
		in[i] = tmp[i];
	return ans;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> in[i];
	cout << quick_sort(0, n, in, temp) << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 100000;

int n, head, max;
pair<pair<int, int>, int> input[max_n];
int stack[max_n], hp[max_n], temp[max_n], father[max_n];

int search(const int stack[], int first, int last, int value){
	if(last == first || stack[first] >= value)
		return first-1;

	while(first + 1 < last){
		int mid = (first + last) / 2;
		if(stack[mid] >= value)
			last = mid;
		else first = mid;
	}

	return first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> input[i].first.first >> input[i].first.second;
		input[i].second = i + 1;
	}
	sort(input, input + n);

	for(int i = 0; i < n; i++){
		int mol = input[i].first.first;
		int j = i;
		for(j = i; j < n && mol == input[j].first.first ; j++){
			int ind = search(stack, 0, head, input[j].first.second);
			temp[j] = ind;
			if(ind >= 0)
				father[j] = hp[ind];
			else father[j] = -1;
		}

		for(int k = j - 1; k >= i ; k--){
			int ind = temp[k];
			stack[ind+1] = input[k].first.second;
			hp[ind+1] = k;
			if(ind + 1 == head)
				head++;
		}
		i = j - 1;
	}

	cout << head << endl;
	for (int i = hp[head-1]; i != -1; i = father[i])
		cout << input[i].second << " ";
	cout << endl;
	return 0;
}
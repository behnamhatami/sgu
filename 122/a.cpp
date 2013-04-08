#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;
const int max_n = 1000;

int n, u;
string s;
int tp[max_n];
bool in[max_n][max_n];
vector<int> ans;
bool mark[max_n];

void print(){
	bool start = false;
	int size = ans.size();
	for(unsigned int i = 0, j = 0; i < 2 * size && j <= size; i++){
		if(ans[i] == 0)
			start = true;
		if(start){
			printf("%d ", ans[i%size] + 1);
			j++;
		}
	}
	printf("\n");
}

void push(int pl, int val){
	mark[val] = true;
	ans.insert(ans.begin() + pl, val);
}

bool extend_init(){
	int size = ans.size();
	int first = ans[0];
	int last = ans[size - 1];

	for(int i = 0; i < n; i++){
		if(mark[i])
			continue;

		if(in[i][last]){
			push(size, i);
			return true;
		}

		if(in[i][first]){
			push(0, i);
			return true;
		}
	}
	return false;
}

bool extend(){
	int size = ans.size();
	for(int j = size - 2; j >= 0; j--){
		for(int i = 0; i < n; i++){
			if(mark[i])
				continue;
			if(in[i][ans[j]] && in[i][ans[j+1]]){
				push(j + 1, i);
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		stringstream iss(s);
		while(getline(iss, s, ' '))
			in[i][atoi(s.c_str())-1] = true;
	}
	mark[0] = true;
	ans.push_back(0);
	while(ans.size() < n && extend_init());
	while(ans.size() < n && extend());
	
	int size = ans.size();
	if(size < n){
		printf("No solution\n");
		return 0;
	}

	int first = ans[0];
	int last = ans[size - 1];
	
	if(in[first][last]){
		print();
		return 0;
	}else{
		vector<int> new_ans;
		for(int i = 2; i < size; i++){
			if(in[ans[i]][first] && in[ans[i-1]][last]){
				for(int j = i; j < size; j++)
					new_ans.push_back(ans[j]);
				for(int j = i - 1; j >= 0; j--)
					new_ans.push_back(ans[j]);
				ans = new_ans;
				print();
				return 0;
			}
		}
	}
	return 0;
}
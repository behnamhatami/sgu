#include <iostream>
#include <vector>
using namespace std;

#define pt pair<int, int>

const int max_n = 40;
const int need[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, p;
bool in[max_n][max_n];
bool mark[max_n][max_n];
int match[max_n][max_n][2];
vector<pt > ans_v, ans_h;

bool dfs(int x, int y){
	if(mark[x][y])
		return false;
	else 
		mark[x][y] = true;
	
	for(int i = 0; i < 4; i++){
		int xn = x + need[i][0];
		int yn = y + need[i][1];
		if((xn < 0) | (xn >= n) | (yn < 0) | (yn >= n) | in[xn][yn])
			continue;
		if((match[xn][yn][0] == -1 && match[xn][yn][1] == -1) | (dfs(match[xn][yn][0], match[xn][yn][1]))) {
			match[xn][yn][0] = x;
			match[xn][yn][1] = y;
			match[x ][y ][0] = xn;
			match[x ][y ][1] = yn;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	int a, b;
	for(int i = 0; i < p; i++){
		cin >> a >> b;
		a--;
		b--;
		in[a][b] = true;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			match[i][j][0] = match[i][j][1] = -1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!in[i][j] && match[i][j][0] == -1 && match[i][j][1] == -1){
				if(!dfs(i, j)){
					cout << "No" << endl;
					return 0;
				}
			}
			for(int k = 0; k < n; k++)
				for(int l = 0; l < n; l++)
					mark[k][l] = false;
		}
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(!in[i][j]){
				if(match[i][j][0] == i && match[i][j][1] > j)
					ans_v.push_back(pt(i, j));
				if(match[i][j][1] == j && match[i][j][0] > i)
					ans_h.push_back(pt(i, j));
			}
	cout << ans_h.size() << endl;
	for(unsigned int i = 0; i < ans_h.size(); i++)
		cout << ans_h[i].first + 1 << " " << ans_h[i].second + 1 << endl;
	cout << ans_v.size() << endl;
	for(unsigned int i = 0; i < ans_v.size(); i++)
		cout << ans_v[i].first + 1 << " " << ans_v[i].second + 1 << endl;

	return 0;
}
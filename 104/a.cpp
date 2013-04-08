#include <iostream>
using namespace std;

const int max_n = 100;
const int max_m = max_n;

int n, m;
int in[max_n][max_n];
int dy[max_n][max_m][2];
int ans[max_n];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> in[i][j];

	dy[0][0][0] = in[0][0];
	dy[0][0][1] = 0;

	for(int j = 1; j < m; j++)
		if (dy[0][j - 1][0] > in[0][j]){
			dy[0][j][0] = dy[0][j - 1][0];
			dy[0][j][1] = dy[0][j - 1][1];
		}else{
			dy[0][j][0] = in[0][j];
			dy[0][j][1] = j;
		}

	for(int i = 1; i < n; i++)
		for(int j = i ; j < m; j++){
			int here = dy[i - 1][j - 1][0] + in[i][j];
			if (j == i || dy[i][j - 1][0] <= here){
				dy[i][j][0] = here;  
				dy[i][j][1] = j;
			}else{
				dy[i][j][0] = dy[i][j - 1][0];
				dy[i][j][1] = dy[i][j - 1][1];
			}
		}

	cout << dy[n-1][m-1][0] << endl;
	for(int i = n - 1, j = m - 1; i >= 0; i--){
		ans[i] = dy[i][j][1];
		j = dy[i][j][1] - 1;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i]+1 << " ";
	cout << endl;
	return 0;
}
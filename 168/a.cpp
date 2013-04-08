#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 1000;

int n, m;
int in[max_n][max_n];

int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d",&in[i][j]);


	for (int j = m - 1; j >= 0; j--)
		for (int i = n - 1; i >= 0; i--){
			in[i][j] = min(in[i][j], in[min(i+1, n - 1)][j]);
			if(j != m - 1)
				in[i][j] = min(in[i][j], in[max(i-1, 0)][j+1]);
		}

	for (int i = 0; i < n; i++ , printf("\n"))
		for (int j = 0; j < m; j++)
			printf("%d ", in[i][j]);
	return 0;
}

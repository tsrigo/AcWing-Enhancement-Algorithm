// Problem: 机器分配
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1015/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
using namespace std;

const int N = 11, M = 16;

int f[N][M];
int w[N][M];
int n, m;

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> w[i][j];
			
	for (int i = 1; i <= n; i ++ ){
		for (int j = 1; j <= m; j ++ ){
			f[i][j] = f[i - 1][j];
			for (int k = 1; k <= j; k ++ ){
				f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
			}
		}
	}
	
	// max : f[n][m]
	cout << f[n][m] << endl;
	
	int way[N];
	int j = m;
	for(int i = n; i >= 1; i -- ){
		for (int k = 0; k <= j; k ++ ){
			if (f[i][j] == f[i - 1][j - k] + w[i][k]){
				way[i] = k;
				j -= k;
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; i ++ ){
		cout << i << " "  << way[i] << endl;
	}
	return 0;
}
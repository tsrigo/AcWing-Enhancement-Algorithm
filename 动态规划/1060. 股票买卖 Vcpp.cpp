// Problem: 股票买卖 V
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1060/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;

int n;
int f[N][3], w[N];

// f[i]表示在前i天中的股票中选，利润的最大值
// 0, 1, 2分别表示手中无股无冷，手中无股有冷，手中有股
// 合法的转移：0 > 0, 0 > 2, 1 > 0, 2 > 2, 2 > 1

int main(void){
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
	
	memset(f, -0x3f, sizeof f);
	// 合法初态(入口)：f[0][0] = 0;
	f[0][0] = 0;
	
	for (int i = 1; i <= n; i ++ ){
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = f[i - 1][2] + w[i];
		f[i][2] = max(f[i - 1][0] - w[i], f[i - 1][2]);
	}
	
	cout << max(f[n][0], f[n][1]);
	// 注意此处答案并不是f[n][0], 因为有可能刚好最后一天把股票卖掉，仍处于冷藏期
	return 0;
}
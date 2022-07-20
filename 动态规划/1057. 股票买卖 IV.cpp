// Problem: 股票买卖 IV
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1059/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010, K = 101;
int n, k;
int f[N][K][2], w[N];

// 两种状态：不持有 - 持有，权值和股票价格有关
// 在卖出算一次交易和买入算一次交易这里存在一些疑惑。

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0;
    
    for (int i = 1; i <= n; i ++ ){
    	for (int j = 0; j <= k; j ++ ){
    		f[i][j][0] = f[i - 1][j][0];
    		if (j >= 1)	f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j - 1][1] + w[i]);
    		f[i][j][1] = max(f[i - 1][j][0] - w[i], f[i - 1][j][1]);
    	}
    }
    int res = -1;
    for (int i = 0; i <= k; i ++ ) res = max(res, f[n][i][0]);
    cout << res << endl;
    return 0;
}
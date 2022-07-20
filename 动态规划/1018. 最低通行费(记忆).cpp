#include<iostream>
#include<cstring>
using namespace std;

const int N = 105, INF = 0x3f3f3f3f;

int n;
int w[N][N], f[N][N];

int dp(int x, int y){
    if (f[x][y] >= 0) return f[x][y];       // 已求解
    if (x == 1 && y == 1) return w[x][y];   // 特判左上角  
    if (x <= 0 || y <= 0) return INF;       // 边界情况

    int t = INF;
    t = min(t, dp(x - 1, y));               // 更新最小值，分两行可避免特判起点
    t = min(t, dp(x, y - 1));

    return f[x][y] = t + w[x][y];           // 不要忘了加上权值
}

int main(void){
    cin >> n;
    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++ ){
            cin >> w[i][j];
        }
    }

    memset(f, -1, sizeof f);                // 记忆化搜索的初始化，因为本题费用都是正数，应该可以 0 应该也是可以的

    cout << dp(n, n);

    return 0;
}
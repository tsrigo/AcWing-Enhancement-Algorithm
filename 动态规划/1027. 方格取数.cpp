#include<iostream>
#include<algorithm>
using namespace std;

const int N = 15;

int f[N * 2][N][N], w[N][N];
int n;

int main(void){
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) w[a][b] = c;    // 整个逗号表达式的值为系列中最后一个表达式的值。
    
    for (int k = 2; k <= n + n; k ++ ){
        for (int i1 = 1; i1 <= n; i1 ++ ){
            for (int i2 = 1; i2 <= n; i2 ++ ){
                int j1 = k - i1, j2 = k - i2;
                if (j1 <= n && j2 <= n && j1 >= 0 && j2 >= 0){
                    int t = w[i1][j1];                      // 判断有没有走到同一个点上
                    if (i1 != i2) t += w[i2][j2];
                    
                    int &x = f[k][i1][i2];                  // 四种状态转移
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);

                }
            }
        }
    }

    cout << f[n + n][n][n];

    return 0;
}
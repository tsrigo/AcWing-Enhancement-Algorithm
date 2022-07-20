#include<iostream>
using namespace std;

const int N = 111;

int n, t;
int f[N], w[N];

int main(void){
    cin >> t;
    while (t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++ )  cin >> w[i];

        int ans = 0;                            // 最终答案，每次得到一个f的值就更新一下，最大值并不是f[n]

        for (int i = 1; i <= n; i ++ ){         // 下标从 1 开始
            f[i] = 1;                           // 每个 f 都至少是 1 
            for (int j = 1; j < i; j ++ ){
                if (w[j] < w[i])                // 更新的前提条件
                    f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }

        for (int i = n; i ; i -- ){             // 结尾是 n ，就从 n 开始
            f[i] = 1;
            for (int j = n; j > i ; j -- ){
                if (w[j] < w[i])                // 这个可以画图想象一下
                    f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }

        cout << ans << endl;
    }
    return 0;
}
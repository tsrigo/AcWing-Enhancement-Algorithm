#include<iostream>
using namespace std;

const int N = 100;

int n, ans = N;
int w[N], up[N], down[N];

void dfs(int u, int su, int sd){            // 层数，上升序列数，下降序列数
    if (su + sd >= ans)                     // 十分重要的剪枝
        return;
    if (u == n){
        ans = min(ans, su + sd);
        return;
    }
    // 下降的部分
    int k = 0, t = down[sd];
    while (k < sd && down[k] < w[u]) k ++ ;

    if (k == sd) down[k] = w[u];            // 这部分可以参考导弹拦截一题
    else {
        t = down[k];
        down[k] = w[u];
    }
    if (k == sd) dfs(u + 1, su, sd + 1);
    else dfs(u + 1, su, sd);

    down[k] = t;                            // 必不可少的回溯

    // 上升部分
    k = 0, t = up[su];
    while (k < su && up[k] > w[u]) k ++ ;

    if (k == su) up[k] = w[u];
    else {
        t = up[k];
        up[k] = w[u];
    }
    if (k == su) dfs(u + 1, su + 1, sd);
    else dfs(u + 1, su, sd);

    up[k] = t;
}

int main(void){
    while (cin >> n, n){
        for (int i = 0; i < n; i ++ )
            cin >> w[i];
        ans = n;                            // 对全局变量的初始化要敏感！
        dfs(0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}
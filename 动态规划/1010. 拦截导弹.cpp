#include<iostream>
using namespace std;

const int N = 1005;

int w[N], g[N], f[N];

int n;

int main(){
    
	while (cin >> w[n]) n ++ ;                  // 小技巧，解决没有给出输入个数的情况
	
	int ans1 = 0;                               // 此段求最长不上升子序列
	for (int i = 0; i < n; i ++ ){
	    f[i] = 1;
	    for (int j = 0; j < i; j ++ )
	        if (w[j] >= w[i])
	            f[i] = max(f[i], f[j] + 1);
        ans1 = max(ans1, f[i]);
	}
    cout << ans1 << endl;
    
    int cnt = 0;                                // 记录序列个数
    for (int i = 0; i < n; i ++ ){
        int k = 0;
        while (k < cnt && g[k] < w[i]) k ++ ;   // 由于g[N]单增，故可这样求
        if (k >= cnt){
            g[cnt] = w[i];                      // 此时g[cnt]是大于w[i]的最小值
            cnt ++ ;                            // 前后顺序不能颠倒
        }
        else
            g[k] = w[i];
    }
    cout << cnt << endl;
	return 0;
}
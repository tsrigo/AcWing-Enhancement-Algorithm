#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 10010;

PII city[N];
int n, f[N];

int main(void){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d%d", &city[i].x, &city[i].y);

    sort(city + 1, city + n + 1);   // 注意下标从 1 开始

    int ans = 0;
    for (int i = 1; i <= n; i ++ ){
        f[i] = 1;                   // 注意dp要初始化
        for (int j = 1; j < n; j ++ ){
            if (city[i].y > city[j].y)
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    
    cout << ans << endl;
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

const int N = 105, INF = 0x3f3f3f3f;

int n;
int w[N][N], f[N][N];

int main(void){
    cin >> n;
    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++ ){
            cin >> w[i][j];
        }
    }
    
    memset(f, 0x3f, sizeof f);
    f[1][1] = w[1][1];

    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++ ){
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + w[i][j];
        }
    }

    cout << f[n][n];

    return 0;
}
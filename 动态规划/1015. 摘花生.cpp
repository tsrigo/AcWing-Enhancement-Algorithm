#include<iostream>
using namespace std;

const int N = 105, INF = 0x3f3f3f3f;

int n, r, c;
int w[N][N], f[N][N];

int main(void){
    cin >> n;
    while (n -- ){
        cin >> r >> c;
        for (int i = 1; i <= r; i ++ )
            for (int j = 1; j <= c; j ++ ){
                cin >> w[N][N];
                if (i == 1 || j == 1) f[i][j] = INF;
            }

        f[1][1] = w[1][1]; 

        for (int i = 1; i <= r; i ++ ){
            for (int j = 1; j <= c; j ++ ){
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
            }
        }

        cout << f[r][c] << endl;
    }
    return 0;
}
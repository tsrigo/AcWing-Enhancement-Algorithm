// Problem: 玉米田
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/329/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

typedef long long ll;

int n, m;
ll f[N][M];

ll ban[N];
vector<ll> state, fw[M];

bool check(int state)
{
    for (int i = 0; i + 1 < m; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int main(void){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++ ){
    	for (int j = 0; j < m; j ++ ){
    		int x;
    		cin >> x;
    		ban[i] += !x * (1 << j);
    	}
    }
    
    for (int i = 0; i < 1 << m; i ++ ){
    	if (check(i)){
    		state.push_back(i);
    	}
    }
    
    int len = state.size();
    for (int i = 0; i < len; i ++ ){
    	for (int j = 0; j < len; j ++ ){
    		ll a = state[i], b = state[j];
    		if ((a & b) == 0){
    			fw[i].push_back(j);
    		}
    	}
    }
   
   	f[0][0] = 1; 
    for (int i = 1; i <= n + 1; i ++ ){
    	for (int a = 0; a < len; a ++ ){
    		ll aa = state[a];
    		if (!(aa & ban[i])){
	    		for (int b : fw[a]){
	    			f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
	    		}
    		}
    	}	
    }
    
    cout << f[n + 1][0] << endl;
    return 0;
}


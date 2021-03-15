#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 505;
int n, m;
int a[MXN][MXN];
int dp[MXN][1024];
int res[MXN];

bool Dp(int i, int xorr) {
    if(i == n) return xorr > 0;
    if(dp[i][xorr] != -1) return dp[i][xorr];
    for(int j = 0; j < m; j++) {
        if(Dp(i + 1, xorr ^ a[i][j])) {
            res[i] = j;
            return dp[i][xorr] = 1;
        }
    }
    return dp[i][xorr] = 0;
} 
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    if(Dp(0, 0)) {
        cout << "TAK" << endl;
        for(int i = 0; i < n; i++) {
            cout << res[i] + 1 << ' ';
        } cout << endl;
    } else { 
        cout << "NIE" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, k; 
int batch[21], cost[21][21], rat[21][21];
int dp[21][2][1010];

// dp[b][w][p] = max(dp[b + 1][0][p], dp[i][1][p + cost[b][j] + x] + rat[b][j]) x = batch[b] : 0

int Dp(int b, int o, int p) {
    if(b == n) return 0;
    if(dp[b][o][p] != -1) return dp[b][o][p];
    int ans = Dp(b + 1, 0, p), tmp = 0, x = !o ? batch[b] : 0;
    for(int j = 0; j < m; j++) {
        if(p + cost[b][j] + x <= k)
            tmp = max(tmp, Dp(b, 1, p + cost[b][j] + x) + rat[b][j]);
    }
    return dp[b][o][p] = max(ans, tmp);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) {
            cin >> batch[i];
        }
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) { 
                cin >> cost[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> rat[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout << Dp(0, 0, 0) << endl;   
    }
    return 0;
}
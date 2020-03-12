#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// int n, W;
int p[105], c[105], w[105];
int dp[105][10005]; 

int Dp(int n, int W) {
    memset(dp, 0, sizeof dp);
    bool cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur ^= 1;
        for(int j = W; j >= 0; j--) {
            int ans = dp[cur ^ 1][j];
            if(j + w[i] <= W) {
                ans = max(ans, dp[cur ^ 1][j + w[i]] + p[i]);
                ans = max(ans, dp[cur][j + w[i]] + p[i]);
            }
            dp[cur][j] = ans;
        }
    }
    return dp[cur][0];
}

void sol() {
    int n, W;
    cin >> n >> W;
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> c[i] >> w[i];
        W -= c[i] * w[i];
    }
    if(W < 0)cout << "Impossible" << endl;
    else cout << Dp(n, W) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}
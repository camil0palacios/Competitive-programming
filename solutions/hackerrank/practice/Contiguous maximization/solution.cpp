#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 500;
int n, m, k; 
ll a[MXN][MXN];
ll dp[MXN][MXN];
ll sum[MXN][MXN];

ll Dp(int i, int x) {
    if(i == n) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    ll ans = 0;
    for(int j = 0; j + x <= k; j++) {
        ans = max(ans, Dp(i + 1, x + j) + sum[i][j]);
    }
    return dp[i][x] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int l = 1; l <= m; l++) {
            for(int r = l; r <= m; r++) {
                ll s = a[i][r] - a[i][l - 1]; 
                int sz = r - l + 1;
                sum[i][sz] = max(sum[i][sz], s);
            }
        }
    }
    memset(dp, -1, sizeof dp);
    cout << Dp(0, 0) << endl;
    return 0;
}
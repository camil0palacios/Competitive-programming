#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 75;
int n, m, k;
int a[MXN][MXN];
int dp[MXN][MXN][MXN][MXN/2];

int go(int i, int j, int r, int x) {
    if(i == n) return r == 0 ? 0 : -INF;
    if(dp[i][j][r][x] != -1) return dp[i][j][r][x];
    int ans = -INF;
    if(j == m) ans = go(i + 1, 0, r, 0);
    else {
        ans = go(i, j + 1, r, x);
        if(x < m / 2) ans = max(ans, go(i, j + 1, (r + a[i][j]) % k, x + 1) + a[i][j]);
    }
    return dp[i][j][r][x] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0, 0) << endl;
    return 0;
}
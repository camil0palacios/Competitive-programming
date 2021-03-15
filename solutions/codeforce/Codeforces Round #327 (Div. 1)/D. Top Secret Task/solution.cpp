#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 155;
int a[MXN];
ll dp[2][MXN][MXN*MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, s;
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bool cur = 0;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        cur ^= 1;
        memset(dp[cur][0], 0, sizeof dp[cur][0]);
        for(int j = 1; j <= i; j++) {
            for(int k = 0; k <= i*j; k++) {
                dp[cur][j][k] = dp[cur^1][j][k];
                if(k >= i - j) dp[cur][j][k] = min(dp[cur][j][k], dp[cur^1][j-1][k-(i - j)] + a[i]);
            }
        }
    }
    ll ans = 1e18;
    for(int i = 0; i <= min(n*(n+1)/2, s); i++) ans = min(ans, dp[cur][k][i]);
    cout << ans << endl;
    return 0;
}
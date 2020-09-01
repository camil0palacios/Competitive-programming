#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = 1e9 + 5;
const int MXN = 110;
const int MXV = 100010;
int n, k;
int v[MXN], w[MXN];
ll dp[MXN][MXV];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    int sv = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        sv += v[i];
    }
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= sv; j++) 
            dp[i][j] = INF;
    dp[n][0] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= sv; j++) {
            dp[i][j] = dp[i + 1][j];
            if(j - v[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= sv; i++) {
        if(dp[0][i] <= k)
            ans = max(ans, (ll)i);
    }
    cout << ans << endl;
    return 0;
}
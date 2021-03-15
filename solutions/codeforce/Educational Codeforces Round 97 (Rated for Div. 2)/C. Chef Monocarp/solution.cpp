#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 202;
int n;
int a[MXN];
int dp[MXN][2*MXN];

// int dp[i][t] = min(dp[i][t + 1], dp[i + 1][t + 1] + |t - a[i]|)

int go(int i, int t) {
    if(i == n) return 0;
    if(dp[i][t] != -1) return dp[i][t];
    int ans = INF;
    if(t < 300) 
        ans = min(go(i, t + 1), go(i + 1, t + 1) + abs(t - a[i]));
    return dp[i][t] = ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    // memset(dp, -1, sizeof dp);
    // cout << go(0, 1) << endl;
    for(int i = 0; i < n; i++) for(int j = 1; j <= 400; j++) dp[i][j] = INF;
    for(int i = n; i >= 0; i--) {
        for(int t = 400; t >= 1; t--) {
            if(i == n) dp[i][t] = 0;
            if(t < 300) 
                dp[i][t] = min(dp[i][t + 1], dp[i + 1][t + 1] + abs(t - a[i]));
        }
    }
    cout << dp[0][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
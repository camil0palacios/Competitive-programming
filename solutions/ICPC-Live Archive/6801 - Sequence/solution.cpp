#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1100;
int n, k;
int dp[MXN][MXN];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int go(int i, int one) {
    if(i == k) return one == 0;
    if(dp[i][one] != -1) return dp[i][one];
    int ans = 0;
    if(one < n) add(ans, go(i + 1, one + 1) * (n - one) % mod);
    if(one) add(ans, go(i + 1, one - 1) * one % mod);
    return dp[i][one] = ans;
}

void solve() {
    cin >> n >> k;
    int one = 0;
    for(int i = 0; i < n; i++) {
        char x; cin >> x;
        one += x - '0';
    }
    memset(dp, 0, sizeof dp);
    dp[k][0] = 1;
    for(int i = k - 1; i >= 0; i--) {
        for(int j = 0; j <= n; j++) {
            if(j < n) add(dp[i][j], dp[i + 1][j + 1] * (n - j) % mod);
            if(j) add(dp[i][j], dp[i + 1][j - 1] * j % mod);
        }
    }
    cout << dp[0][one] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" <<  cs << ": ";
        solve();
    }
    return 0;
}
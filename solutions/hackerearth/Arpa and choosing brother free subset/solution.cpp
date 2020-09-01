#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, k;
int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    cnt[0] = 1;
    for(int i = 1; i < n; i++) {
        int u; cin >> u;
        cnt[u]++;
    }
    ll dp[2][k + 1];
    memset(dp, 0, sizeof dp);
    dp[0][k] = 1;
    bool cur = 0;
    for(int i = n; i >= 0; i--) {
        cur ^= 1;
        for(int j = k; j >= 0; j--) {
            dp[cur][j] = dp[cur ^ 1][j];
            if(j + 1 <= k) {
                dp[cur][j] = (dp[cur][j] + cnt[i] * dp[cur ^ 1][j + 1]) % MOD;
            }
        }
    } 
    cout << dp[cur][0] << endl;
    return 0;
}
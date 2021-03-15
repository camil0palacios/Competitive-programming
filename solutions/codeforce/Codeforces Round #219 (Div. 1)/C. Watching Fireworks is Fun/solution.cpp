#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXN = 200005;
const int MXM = 305;
int a[MXN], b[MXN], t[MXN];
int q[MXN];
ll dp[2][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }
    memset(dp, 0, sizeof dp);
    bool cur = 0;
    for(int i = 1; i <= m; i++) {
        ll tt = t[i] - t[i - 1]; 
        int l = 1, r = 0, k = 1;
        for(int j = 1; j <= n; j++) {
            while(l <= r && abs(j - q[l]) > tt*d) l++;
            while(k <= n && abs(k - j) <= tt*d) {
                while(l <= r && dp[cur ^ 1][k] >= dp[cur ^ 1][q[r]]) r--;
                q[++r] = k; k++;
            }
            dp[cur][j] = dp[cur ^ 1][q[l]] + (ll)b[i] - abs(a[i] - j);
        }
        cur ^= 1;
    }
    cur ^= 1;
    ll ans = -INF;
    for(int j = 1; j <= n; j++) {
        ans = max(ans, dp[cur][j]);
    }
    cout << ans << endl;
    return 0;
}
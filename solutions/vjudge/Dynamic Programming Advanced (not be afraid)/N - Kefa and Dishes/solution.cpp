#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 20;
int n, m, k;
ll c[MXN][MXN], a[MXN];
ll dp[(1 << MXN) + 1][MXN];

ll Dp(int msk, int lst) {
    if(__builtin_popcount(msk) == m) return 0;
    if(dp[msk][lst] != -1) return dp[msk][lst];
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1)) {
            ans = max(ans, Dp(msk | (1 << i), i) + a[i] + c[lst][i]);
        }
    }
    return dp[msk][lst] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    for(int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        c[x-1][y-1] = z;
    }
    memset(dp, -1, sizeof dp);
    ll ans = Dp(0, 19);
    cout << ans << endl;
    return 0;
}
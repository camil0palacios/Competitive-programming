#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
int n;
int l[18], d[18];
ll dp[1 << 18];

ll go(int msk) {
    if(msk == (1 << n) - 1) return 0;
    if(dp[msk] != -1) return dp[msk];
    ll ans = -INF;
    int st = __builtin_popcount(msk);
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1)) {
            ll val = (ll)n * l[i] + (ll)i * d[i] * st * (st + 1) / 2 - (ll) n * i * d[i] * st;
            ans = max(ans, go(msk | (1 << i)) + val);
        }
    }
    return dp[msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    memset(dp, -1, sizeof dp);
    cout << go(0) << endl;
    return 0;
}
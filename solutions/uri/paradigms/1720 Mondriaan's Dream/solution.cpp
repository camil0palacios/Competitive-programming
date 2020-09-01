#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 12;
int n, m;
ll dp[MXN][1 << MXN];

ll Dp(int idx, int msk) {
    if(idx == m) return msk == 0;
    if(dp[idx][msk] != -1) return dp[idx][msk];
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        int j = 0, ok = 1;
        while(j < n && ok) {
            int a = (msk >> j) & 1, b = (i >> j) & 1;
            if(a && b) ok = 0;
            else if(!a && !b){
                int k = j + 1, c = (msk >> k) & 1, d = (i >> k) & 1;
                if(!c && !d && k < n) j += 2;
                else ok = 0;
            }
            else j++;
        }
        if(ok) ans += Dp(idx + 1, i);
    }
    return dp[idx][msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> m && (n || m)) {
        memset(dp, -1, sizeof dp);
        cout << Dp(0, 0) << endl;
    }
    return 0;
}
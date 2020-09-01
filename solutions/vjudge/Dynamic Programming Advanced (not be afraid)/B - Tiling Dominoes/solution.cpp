#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n, m;
ll dp[101][1 << 12];
ll memo[101][101];

ll Dp(int idx, int msk) {
    if(idx == n) return msk == 0 ? 1 : 0;
    if(dp[idx][msk] != -1) return dp[idx][msk];
    ll ans = 0;
    for(int nw_msk = 0; nw_msk < (1 << m); nw_msk++) {
        int ok = 1, j = 0;
        while(j < m) {
            int a = (msk >> j) & 1, b = (nw_msk >> j) & 1;
            if(a && b) { ok = 0; break; }
            if(a == b) {
                if(j + 1 < m) {
                    int c = (msk >> (j + 1)) & 1, d = (nw_msk >> (j + 1)) & 1;
                    if(c == d && c == 0) j += 2;
                    else { ok = 0; break; }
                } else { ok = 0; break; }
            } else {
                j++;
            }
        }
        if(ok) ans += Dp(idx + 1, nw_msk);
    }
    return dp[idx][msk] = ans; 
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);   
    memset(memo, 0, sizeof memo);
    while(cin >> n >> m) {
        if(m > n) swap(n, m);
        if(memo[n][m]) cout << memo[n][m] << endl;
        else {
            memset(dp, -1, sizeof dp);
            memo[n][m] = Dp(0, 0);
            cout << memo[n][m] << endl;
        }
    }
    return 0;
}
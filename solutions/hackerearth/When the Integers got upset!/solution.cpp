#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
const int INF = 1e9;
int n, a[MXN], p[MXN];
int dp[1 << 15][15][15];

int go(int msk, int j, int k) {
    if(msk == (1 << n) - 1) return 0;
    if(dp[msk][j][k] != -1) return dp[msk][j][k];
    int ans = INF;
    int x = __builtin_popcount(msk);
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1)) {
            int val = ((a[i] ^ a[j]) ^ a[k]) * p[x];
            if(x <= 1) val = 0;
            ans = min(ans, go(msk | (1 << i), i, j) + val);
        }
    }
    return dp[msk][j][k] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> p[i];
        memset(dp, -1, sizeof dp);
        cout << go(0, 0, 0) << endl;
    }
    return 0;
}
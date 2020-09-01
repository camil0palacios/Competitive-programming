#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n, a[21][21];
ll dp[20][1 << 20];

ll Dp(int idx, int msk) {
    if(idx == n) return msk == (1 << n) - 1;
    if(dp[idx][msk] != -1) return dp[idx][msk]; 
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1) && a[idx][i]) {
            ans += Dp(idx + 1, msk | (1 << i));
        }
    }
    return dp[idx][msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout << Dp(0, 0) << endl;
    }
    return 0;
}
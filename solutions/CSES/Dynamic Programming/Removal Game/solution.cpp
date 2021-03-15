#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 5050;
ll dp[MXN][MXN];
ll a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int l = n - 1; l >= 0; l--) {
        dp[l][l] = a[l];
        for(int r = l + 1; r < n; r++) {
            ll x = (l + 2 <= r ? dp[l + 2][r] : 0);
            ll y = (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0);
            ll z = (l <= r - 2 ? dp[l][r - 2] : 0);
            dp[l][r] = max(a[l] + min(x, y), a[r] + min(y, z));
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
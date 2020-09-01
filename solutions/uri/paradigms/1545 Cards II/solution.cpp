#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a[10010];
ll dp[2][10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // dp[l][r] = max(a[l] + dp[l + 1][r - 1], a[r] + dp[l + 1][r - 1]);
        memset(dp, 0, sizeof dp);
        for(int l = n - 2; l >= 0; l--) {
            for(int i = 0; i < n; i++) dp[1][i] = dp[0][i], dp[0][i] = 0;
            // dp[0][l + 1] = max(a[l], a[l + 1]);
            dp[0][l + 1] = max(a[l], a[l + 1]);
            for(int r = l + 2; r < n; r++) {
                dp[0][r] = max(a[l] + dp[1][r - 1], a[r] + dp[1][r - 1]);
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 255;
const int MXM = 55;
int n, m, c[MXM];
ll dp[MXM][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    memset(dp, 0, sizeof dp);
    dp[m][n] = 1;
    for(int i = m - 1; i >= 0; i--) {
        for(int coin = n; coin >= 0; coin--) {
            dp[i][coin] = dp[i + 1][coin];
            if(coin + c[i] <= n) dp[i][coin] += dp[i][coin + c[i]];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
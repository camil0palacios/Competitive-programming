#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n, k, s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> k >> s, n || k || s) {
        ll dp[n + 2][k + 2][s + 2];
        memset(dp, 0, sizeof dp);
        dp[n + 1][k][s] = 1;
        // dp[i][j][acc] = dp[i][j + 1][acc] + dp[i + 1][j + 1][acc + j]
        for(int i = n; i >= 1; i--) {
            for(int j = k; j >= 0; j--) {
                for(int acc = s; acc >= 0; acc--) {
                    dp[i][j][acc] = dp[i + 1][j][acc];
                    if(acc + j <= s && j < k) dp[i][j][acc] += dp[i + 1][j + 1][acc + i];
                }
            }
        }
        cout << dp[1][0][0] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

/* *
    dp[i][j] = j == 0 ? dp[i - 1][0] + dp[i - 1][i] : for x in max(0, i - x) sum(dp[i - x])
    use prefix sum to do in o(1) so dp[i][1] = ps[i] - ps[i - k]
 */

const int MXN = 10010;
int n, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    if(k == 0) cout << 1 << endl;
    else {
        ll dp[n + 1][2], sum[n + 1];
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        dp[0][0] = dp[0][1] = 1;
        sum[0] = 1;
        sum[1] = sum[0] + 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            sum[i + 1] = sum[i] + dp[i][0]; 
            int s = i - k;
            if(s >= 0) dp[i][1] = sum[i] - sum[s];
            else dp[i][1] = sum[i];
        }
        cout << dp[n - 1][0] + dp[n - 1][1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 55;
const int MAXK = 35;
const int MAXP = MAXN * MAXK;
const int INF = 1e9;
int n, k, p;
int a[MAXN][MAXK];
int dp[MAXN][MAXP];

// int go(int i, int j) {
//     if(i == n) return j == p ? 0 : -INF;
//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = go(i + 1, j);
//     for(int x = 1; x <= k && j + x <= p; x++) {
//         ans = max(ans, go(i + 1, j + x) + a[i][x - 1]);
//     }
//     return dp[i][j] = ans;
// }

void sol() {
    cin >> n >> k >> p;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            if(j) a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= p; j++) {
            dp[i][j] = -INF;
        }
    }
    // dp[i][p] = max(dp[i + 1][p], dp[i + 1][p - j]) j <= p
    dp[n][p] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = p; j >= 0; j--) {
            int ans = dp[i + 1][j];
            for(int x = 1; x <= k && x + j <= p; x++){
                ans = max(ans, dp[i + 1][j + x] + a[i][x - 1]);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[0][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}
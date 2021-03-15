#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 25;
int cost[MXN], popularity[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> cost[i] >> popularity[i];
        }        
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = dp[i + 1][j];
                if(cost[i] <= j) dp[i][j] = max(dp[i][j], dp[i + 1][j - cost[i]] + popularity[i]);
            }
        }
        cout << dp[0][m] << endl;
    }
    return 0;
}
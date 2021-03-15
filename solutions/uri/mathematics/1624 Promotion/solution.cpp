#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 101;
int v[MXN], w[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            cin >> v[i] >> w[i];
        }
        cin >> m;
        int dp[2][m + 1];
        memset(dp, 0, sizeof dp);
        bool cur = 0;
        for(int i = n - 1; i >= 0; i--) {
            cur ^= 1;
            for(int j = 0; j <= m; j++) {
                dp[cur][j] = dp[cur^1][j];
                if(w[i] <= j) dp[cur][j] = max(dp[cur][j], dp[cur^1][j - w[i]] + v[i]);
            }
        }
        cout << dp[cur][m] << endl;
    }
    return 0;
}
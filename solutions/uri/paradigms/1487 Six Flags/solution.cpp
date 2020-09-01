#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int d[610], p[110];

// dp[time] = max(dp[time + d[i]] + p[i])

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t, cs = 0;
    while(cin >> n >> t && (n || t)) {
        for(int i = 0; i < n; i++) {
            cin >> d[i] >> p[i];
        }
        int dp[t + 1], mx = 0;
        memset(dp, 0, sizeof dp);
        for(int i = t - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(i + d[j] <= t)
                    dp[i] = max(dp[i], dp[i + d[j]] + p[j]);
            }
            mx = max(mx, dp[i]);
        }
        cout << "Instancia " << ++cs << endl;
        cout << mx << endl << endl;
    }
    return 0;
}
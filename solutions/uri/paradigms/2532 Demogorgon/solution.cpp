#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    while(cin >> n >> p) {
        int d[n], m[n];
        for(int i = 0; i < n; i++) {
            cin >> d[i] >> m[i];
        } 
        int dp[n + 1][p + 1];
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j <= p; j++) 
                dp[i][j] = INF;
        dp[n][0] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= p; j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][max(0, j - d[i])] + m[i]);
            }
        }
        cout << (dp[0][p] < INF ? dp[0][p] : -1) << endl;
    }
    return 0;
}
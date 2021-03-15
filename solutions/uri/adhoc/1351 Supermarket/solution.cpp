#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double INF = 1e9;
const int MXM = 101;
const int MXN = 100005;
int prod[MXM], idp[MXN];
double p[MXN];
double dp[2][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(2);
    int m, n;
    while(cin >> m >> n, n || m) {
        for(int i = 0; i < m; i++) {
            cin >> prod[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> idp[i] >> p[i];
        }
        // dp[i][j] = min(dp[i][j + 1], if(prod[i] == id[j])dp[i + 1][j + 1]);
        // dp[m][j] = 0
        for(int i = 0; i <= n; i++) {
            dp[1][i] = INF, dp[0][i] = 0;
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j <= n; j++) dp[1][j] = dp[0][j], dp[0][j] = INF;
            for(int j = n - 1; j >= 0; j--) {
                dp[0][j] = min(dp[0][j + 1], prod[i] == idp[j] ? dp[1][j + 1] + p[j] : INF);
            }
        }
        if(dp[0][0] < INF) cout << dp[0][0] << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
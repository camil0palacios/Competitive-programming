#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 3005;
double p[MXN];
double dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]);
            if(j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }
    double ans = 0;
    for(int i = (n + 1) / 2; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}
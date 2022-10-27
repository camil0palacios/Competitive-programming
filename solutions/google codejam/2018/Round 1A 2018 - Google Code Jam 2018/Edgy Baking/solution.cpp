#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;
const int MXP = MXN * 250 + 10;
int w[MXN], h[MXN];
// double dp[MXN][MXP];

void sol() {
    int n; double p;
    cin >> n >> p;
    p /= 2;
    double sum = 0; int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
        p -= w[i] + h[i];
        sum += 2 *(w[i] + h[i]);
        mx = max(mx, max(w[i], h[i]));
    }
    vector<vector<double>> dp(n + 1, vector<double> (n * mx + 1, -1));
    dp[0][0] = 0.0;
    for(int i = 0; i < n; i++) {
        double x = sqrt(w[i] * w[i] + h[i] * h[i] + 0.0);
        double mn = min(w[i], h[i]);
        for(int j = 0; j < dp[i + 1].size(); j++) {
            if(j >= mn && dp[i][j - mn] >= 0.0) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - mn] + x);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    double ans = 0;
    for(int i = 0; i < dp[n].size(); i++) {
        double hi = dp[n][i];
        if(hi >= 0.0 && i <= p)
            ans = max(ans, hi >= p ? p : hi);
    }
    cout << sum + 2*ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(16);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol(); 
    }
    return 0;
}
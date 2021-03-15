#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int Mxn = 1005;
const int Mxt = 2005;
int c[Mxn], v[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t;
    while(cin >> n >> t) {
        for(int i = 1; i <= n; i++) {
            cin >> c[i] >> v[i];
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(t + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= t; j++) {
                ll ans = dp[i - 1][j];
                if(c[i] <= j) ans = max(ans, dp[i][j - c[i]] + v[i]);
                dp[i][j] = ans;
            }
        }
        cout << dp[n][t] << endl;
    }
    return 0;
}
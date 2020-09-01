#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 15;
double ans[15];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    double dp[2][1 << n];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        int a, b; double p;
        cin >> a >> b >> p;
        a--, b--;
        for(int msk = 0; msk < (1 << n); msk++) dp[1][msk] = dp[0][msk], dp[0][msk] = 0;
        for(int msk = 0; msk < (1 << n); msk++) {
            if((msk >> a) & 1) {
                dp[0][msk] = dp[1][msk];
            } else { 
                if((msk >> b) & 1) {
                    dp[0][msk] = dp[1][msk] + dp[1][msk ^ (1 << b)] * p;
                } else {
                    dp[0][msk] = dp[1][msk] * (1 - p);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int msk = 0; msk < (1 << n); msk++) {
            if((msk >> i) & 1){
                ans[i] += dp[0][msk];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << 1 - ans[i] << endl;
    }
    return 0;
}
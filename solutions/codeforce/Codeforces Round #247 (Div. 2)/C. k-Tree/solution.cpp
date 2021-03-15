#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 110;
int n, k, d;
ll dp[MXN][2];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

// dp[i][t] += dp[i + j][t || j == d]

// ll go(int i, int t) {
//     if(i == n) return t;
//     if(dp[i][t] != -1) return dp[i][t];
//     ll ans = 0;
//     for(int j = 1; j <= k; j++) {
//         if(i + j <= n) add(ans, go(i + j, t || j >= d));
//     }
//     return dp[i][t] = ans;
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> d;
    dp[n][1] = 1; 
    for(int i = n - 1; i >= 0; i--) {
        for(int t = 0; t < 2; t++) {
            for(int j = 1; j <= k; j++) {
                if(i + j <= n) {
                    add(dp[i][t], dp[i + j][t || j >= d]);
                }
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
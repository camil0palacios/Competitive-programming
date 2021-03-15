#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef vector<ll> vll;
typedef vector<vll> mat;
const ll mod = 1000000007;

mat mult(mat & a, mat & b) {
    int n = a.size();
    mat c(n, vll(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return c;
}

ll mat_pow(ll b) {
    mat ans = {{1, 0}, {0, 1}};
    mat a = {{1, 1}, {1, 0}};
    while(b) {
        if(b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    ll res = (ans[0][0] + ans[0][1]) % mod;
    return res;
}

ll brute(ll n) {
    ll dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

void solve() {
    ll n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else cout << mat_pow(n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
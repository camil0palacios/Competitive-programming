#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 505;
const int MXS = 125250;
ll dp[2][MXS * 2 + 5];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    sum = (sum + 1) / 2;
    dp[0][sum] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = -sum; j <= sum; j++) 
            dp[1][j + sum] = dp[0][j + sum], dp[0][j + sum] = 0;
        for(int j = -sum; j <= sum; j++) {
            ll ans = 0;
            if(j + i <= sum) add(ans, dp[1][j + i + sum]);
            if(j - i >= -sum) add(ans, dp[1][j - i + sum]);
            dp[0][j + sum] = ans;
        }
    }
    cout << (dp[0][sum] * be(2LL, mod - 2)) % mod << endl;
    return 0;
}